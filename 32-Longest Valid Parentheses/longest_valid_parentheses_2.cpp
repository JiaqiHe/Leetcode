class Solution {
public:
    //stack
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> stk;
        for(int i = 0; i < s.length(); i ++){
            if(s[i] == '(') stk.push(i);
            else {
                if(!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                } else {
                    stk.push(i);
                }
            }
        }
        int res = 0;
        int cur = s.length();
        while(!stk.empty()) {
            int index = stk.top();
            stk.pop();
            res = max(res, cur - index - 1);
            cur = index;
        }
        res = max(res, cur);
        return res;
    }
};
