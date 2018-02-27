class Solution {
public:
    /*
    * 思路：⚠️这个“+”最大的特点是从中心向四个方向延伸，必须一样长，那么我们就希望找到这四个方向能延伸多长，取最小就是某一个中心所能画的最大“+”
    * 先把对应的grid给建出来
    * 之后先对“行”做处理，从左往右正序走一遍，用于统计连续1的个数，并更新（见到0就重新计数）；再从右往左逆序走一遍，也是统计连续1的个数，更新
    * 再对“列”做处理，从上往下正序走一遍，用于统计连续1的个数，并更新；最后从下往上逆序走一遍，此时，更新完的值是最终的值，取其中的最大值
    */
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for(auto mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        //row traversal
        for(int i = 0; i < N; i ++) {
            int ones = 0;
            //正序走一遍
            for(int j = 0; j < N; j ++) {
                if(grid[i][j] == 0) {
                    ones = 0;
                } else {
                    grid[i][j] = ++ones;
                }
            }
            //逆序走一遍
            ones = 0;
            for(int j = N - 1; j >= 0; j --) {
                if(grid[i][j] == 0) {
                    ones = 0;
                } else {
                    grid[i][j] = min(grid[i][j], ++ones);
                }
            }
        }
        
        //column traversal
        for(int j = 0; j < N; j ++) {
            int ones = 0;
            //正序走一遍
            for(int i = 0; i < N; i ++) {
                if(grid[i][j] == 0) {
                    ones = 0;
                } else {
                    grid[i][j] = min(grid[i][j], ++ones);
                }
            }
            //逆序走一遍
            ones = 0;
            for(int i = N - 1; i >= 0; i --) {
                if(grid[i][j] == 0) {
                    ones = 0;
                } else {
                    grid[i][j] = min(grid[i][j], ++ones);
                }
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }
};
