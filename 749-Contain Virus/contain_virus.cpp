class Solution {
public:
    /*
    * 思路：
    * 模拟整个过程
    * 第一步：统计病毒区域以及能够扩散的数量
    * 第二步：选出扩散能力最强的那个群体
    * 第三步：计算需要多少面墙，同时将这些被隔离的病毒标记成“被隔离”
    * 第四步：对于其他病毒区块，进行病毒传播
    * 如此往复
    *
    *
    * 符号规定：
    * 1 - 未被控制的病毒
    * 0 - 未被感染的人群
    * 2 - 已被隔离的病毒
    * 5 - （中间状态）统计病毒区域时被访问过的病毒
    * 3 - （中间状态）计算墙时被访问过的病毒
    * 
    */
    
    // locate virus - helper function: dfs
    /*
    ********************************
    * 第一步：统计病毒区域以及能够扩散的数量
    ********************************
    * 这里，遍历病毒和计算能够扩散的数量可以一起做
    * 只要是1，就说明是病毒，标记为5，并继续遍历四周
    * 如果是0，就说明这一定是这块病毒能够感染到的人群，数量++
    * 在这种情况下，状态2可以被当作0来处理
    */
    void dfs(vector<vector<int>> &grid, int i, int j, unordered_set<int> &res) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 2 || grid[i][j] == 5) return;
        if(grid[i][j] == 0) {
            res.insert(i*13 + j*7);
            return;
        }
        grid[i][j] = 5;
        dfs(grid, i+1, j, res);
        dfs(grid, i-1, j, res);
        dfs(grid, i, j+1, res);
        dfs(grid, i, j-1, res);
        return;
    }
    // locate virus and compute infections
    void locateVirus(vector<vector<int>> &grid, vector<pair<int, int>> &clusters, vector<int> &infections) {
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(grid[i][j] == 1) {
                    clusters.push_back(make_pair(i, j));
                    unordered_set<int> res;
                    dfs(grid, i, j, res);
                    infections.push_back(res.size());
                }
            }
        }
        return;
    }
    
    // compute walls
    /*
    ********************************
    * 第三步：计算需要多少面墙，同时将这些被隔离的病毒标记成“被隔离”
    ********************************
    * 这里，我们只关心病毒的位置，因此仅对标记为5的感兴趣
    * 墙的计算公式：# of walls = # of virus * 4 - # edges between virus * 2 - # of boards
    * 我们要统计的是（1）病毒的数量（2）病毒相邻边的数量（3）边界边的数量
    * （1）病毒的数量：看到标记为5的就加1，同时将其标记改为3
    * （2）病毒相邻边的数量：对病毒来说，检查它的左边和上边是不是病毒，有一加一，有二加二
    * （3）边界边的数量：边界边是指：位于整个grid的边上，或者⚠️和标记为2的相邻！！！
    * 最后，将标记改为2，表示这些病毒已经得到控制
    */
    void dfsForWalls(vector<vector<int>> &grid, int i, int j, int &virus, int &edge, int &board) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 5) return;
        // we know for sure grid[i][j] = 5;
        virus++;
        grid[i][j] = 3;
        // update edge
        if(i > 0 && grid[i-1][j]&1) edge++;
        if(j > 0 && grid[i][j-1]&1) edge++;
        
        // update board
        if(i == 0) board++;
        if(j == 0) board++;
        if(i == grid.size() - 1) board++;
        if(j == grid[0].size() - 1) board++;
        if(i > 0 && grid[i-1][j] == 2) board++;
        if(i < (int)grid.size() - 1 && grid[i+1][j] == 2) board++;
        if(j > 0 && grid[i][j-1] == 2) board++;
        if(j <= (int)grid[0].size() - 2 && grid[i][j+1] == 2) board++;
        // dfs
        dfsForWalls(grid, i+1, j, virus, edge, board);
        dfsForWalls(grid, i-1, j, virus, edge, board);
        dfsForWalls(grid, i, j+1, virus, edge, board);
        dfsForWalls(grid, i, j-1, virus, edge, board);
        grid[i][j] = 2;
        return;
    }
     
    /*
    * 第四步：对于其他病毒区块，进行病毒传播
    * 这里，我们关注的标记是5以及能访问到的0，5代表是病毒（由第一步得来），0代表是能由附近病毒区块将其感染，因此要将其改为病毒的标记：1
    * 同样，如果是5，则改为1，同时继续四个方向遍历
    */
    void contaminate(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 2 || grid[i][j] == 1) return;
        if(grid[i][j] == 0) {
            grid[i][j] = 1;
            return;
        }
        grid[i][j] = 1;
        contaminate(grid, i+1, j);
        contaminate(grid, i-1, j);
        contaminate(grid, i, j+1);
        contaminate(grid, i, j-1);
        return;
    }
    
    
    int containVirus(vector<vector<int>>& grid) {
        int res = 0;
        if(grid.empty() || grid[0].empty()) return res;
        while(true) {
            
            vector<pair<int, int>> clusters;
            vector<int> infections;
            locateVirus(grid, clusters, infections);
            if(clusters.empty()) break;
            // find the max infection and its virus cluster
            int max_infection = 0;
            int index = 0;
            
            for(int i = 0; i < infections.size(); i ++) {
                if(infections[i] > max_infection) {
                    index = i;
                    max_infection = infections[i];
                }
            }
            int virus = 0, edge = 0, board = 0;
            // compute the number of walls needed
            dfsForWalls(grid, clusters[index].first, clusters[index].second, virus, edge, board);
            int walls = virus * 4 - edge * 2 - board;
            res += walls;
            
            // contaminate
            for(int i = 0; i < clusters.size(); i ++) {
                if(i == index) continue;
                contaminate(grid, clusters[i].first, clusters[i].second);
            }
            //用于检查，输出每轮操作之后的情况
            // for(auto r : grid) {
            //     for(auto c : r) {
            //         cout<<c<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            // break;
        }
        return res;
    }
};
