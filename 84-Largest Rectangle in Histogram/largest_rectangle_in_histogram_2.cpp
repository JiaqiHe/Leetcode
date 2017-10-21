class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int res = 0;
        stack<int> stk;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        stk.push(heights[0]);
        
        for(int i = 1; i < heights.size(); i ++){
            while(heights[i] < heights[stk.top()]){
                int idx = stk.top();
                stk.pop();
                res = max(res, heights[idx]*(i-stk.top()-1));
            }
            stk.push(i);
        }
        
        return res;
     }
   }
