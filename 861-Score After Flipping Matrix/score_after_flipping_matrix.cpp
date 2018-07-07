class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.size() == 0 || A[0].size() == 0) return 0;
        int res = A.size() * pow(2, A[0].size() - 1);
        for(int j = 1; j < A[0].size(); j ++) {
            int counter = 0;
            for(int i = 0; i < A.size(); i ++) {
                counter += (A[i][0] == 0 ? (1 - A[i][j]) : A[i][j]);
            }
            res += max(counter, (int)A.size() - counter) * pow(2, A[0].size() - 1 - j);
        }
        return res;
    }
};
