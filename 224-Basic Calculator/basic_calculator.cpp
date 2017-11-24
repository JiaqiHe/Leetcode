class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int sign = 1;
        int res = 0;
        int num = 0;
        for(auto c : s){
            if(isdigit(c)){
                num = num * 10 + c - '0';
            }
            else{
                res += num * sign;
                num = 0;
                if(c == '('){
                    nums.push(res);
                    ops.push(sign);
                    res = 0;
                    sign = 1;
                }
                if(c == ')'){
                    res = ops.top() * res + nums.top();
                    ops.pop();
                    nums.pop();
                }
                if(c == '-') sign = -1;
                if(c == '+') sign = 1;
            }
        }
        res += num * sign;
        return res;
    }
};
