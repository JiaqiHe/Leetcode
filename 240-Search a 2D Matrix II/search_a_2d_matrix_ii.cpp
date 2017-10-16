class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int row_index = 0, column_index = matrix[0].size()-1; 
        while(matrix[row_index][column_index]!=target){
            if(matrix[row_index][column_index] > target){
                column_index--;
            }
            else{
                row_index++;
            }
            if(column_index<0 || row_index>=matrix.size()) return false;
        }
        return true;
    }
};
