class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int left[col], right[col], height[col];
        for(int i = 0; i < col; i++){
            left[i] = 0;
            right[i] = col;
            height[i] = 0;
        }
        for(int i = 0; i < row; i++){
            int cur_left = 0, cur_right = col;
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    left[j] = max(left[j], cur_left);
                    height[j]++;
                }
                else{
                    cur_left = j+1;
                    left[j] = 0;
                    height[j] = 0;
                }
            }
            for(int j = col-1; j >=0; j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], cur_right);
                }
                else{
                    right[j] = col;
                    cur_right = j;
                }
            }
            for(int j = 0; j < col; j++){
                res = max(res, (right[j]-left[j])*height[j]);
            }
        }
        return res;
    }
};
