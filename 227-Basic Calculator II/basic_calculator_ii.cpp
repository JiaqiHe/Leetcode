class Solution {
public:
    int calculate(string s) {
        s += ')';
        int res = 0;
        stack<int> nums, ops;
        ops.push(1);
        int num = 0;
        for(char c : s){
            if(c == ' ') continue;
            if(isdigit(c)){
                num = num * 10 + c - '0';
            }
            else{
                if(!ops.empty() && (ops.top() == 3 || ops.top() == 4)){
                    int pre = nums.top();
                    nums.pop();
                    int op = ops.top();
                    ops.pop();
                    if(op == 3) nums.push(pre*num);
                    if(op == 4) nums.push(pre/num);
                    num = 0;
                }
                else{
                    nums.push(num);
                    num = 0;
                }
                if(c == '+') ops.push(1);
                if(c == '-') ops.push(-1);
                if(c == '*') ops.push(3);
                if(c == '/') ops.push(4);
            }
        }
        while(!ops.empty()){
            res += nums.top() * ops.top();
            nums.pop();
            ops.pop();
        }
        return res;
    }
};
