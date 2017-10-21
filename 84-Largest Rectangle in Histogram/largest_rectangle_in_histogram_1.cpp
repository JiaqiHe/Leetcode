class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        
        left[0] = -1;
        right[heights.size()-1] = heights.size();
        
        for(int i = 1; i < heights.size(); i++){
            int p = i-1;
            while(p >= 0 && heights[i] <= heights[p]) p = left[p];
            left[i] = p;
        }
        
        for(int i = heights.size()-2; i >= 0; i--){
            int p = i+1;
            while(p <= heights.size()-1 && heights[i] <= heights[p]) p = right[p];
            right[i] = p;
        }
        
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            res = max(res, heights[i]*(right[i] - left[i] -1));
        }
        return res;
    }
};
