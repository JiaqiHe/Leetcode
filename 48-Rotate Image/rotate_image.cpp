class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        //first transpose the matrix
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //flip the matrix
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};
