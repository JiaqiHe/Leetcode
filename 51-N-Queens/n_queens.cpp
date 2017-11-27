class Solution {
public:
    void solve(int n, vector<vector<string>> &res, vector<int> &position, int cur){//place cur-th queen
        if(cur == n){
            //output
            vector<string> output;
            for(int i = 0; i < n; i ++){
                string row = "";
                for(int j = 0; j < n; j ++){
                    if(position[i]==j) row += 'Q';
                    else row += '.';
                }
                output.push_back(row);
            }
            res.push_back(output);
            return;
        }
        
        for(int i = 0; i < n; i ++){
            int j;
            for(j = 0; j < cur; j ++){
                if(i == position[j] || abs(cur - j) == abs(i - position[j])) break;
            }
            if(j == cur){
                position[cur] = i;
                solve(n, res, position, cur+1);
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> position(n, 0);
        int cur = 0;
        solve(n, res, position, cur);
        return res;
    }
};
