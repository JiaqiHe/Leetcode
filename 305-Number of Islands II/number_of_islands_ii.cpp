class Solution {
public:
    int findparent(int a, vector<int> &parent){
        if(parent[a] != a) parent[a] = findparent(parent[a], parent);
        return parent[a];
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        vector<int> parent(m*n, -1);
        vector<pair<int, int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        int count = 0;
        for(auto p : positions){
            int row = p.first, col = p.second;
            int index = row * n + col;
            parent[index] = index;
            count++;
            for(auto dir : dirs){
                int r = dir.first + row, c = dir.second + col;
                int idx = r * n + c;
                if(r >= 0 && r < m && c >=0 && c < n && parent[idx] != -1){
                    int p_new = findparent(idx, parent);
                    // int this_p = findparent(index, parent);
                    if(p_new != index){
                        parent[p_new] = index;
                        count--;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
