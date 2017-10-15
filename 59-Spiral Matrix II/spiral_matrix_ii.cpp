class Solution {
public:
    int num = 1;
    void filltheedge(vector<vector<int>> &res, int ptr, int n){
        //first row
        for(int i = ptr; i <= n-1-ptr; i++) res[ptr][i] = num++;
        //last column
        for(int j = ptr+1; j <= n-1-ptr; j++) res[j][n-1-ptr] = num++;
        //last row
        for(int i = n-1-ptr-1; i >= ptr; i--) res[n-1-ptr][i] = num++;
        //first column
        for(int j = n-1-ptr-1; j >= ptr+1; j--) res[j][ptr] = num++;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int i = 0;
        while(n*n>num-1){
            filltheedge(res, i, n);
            i++;
        }
        return res;
    }
};
