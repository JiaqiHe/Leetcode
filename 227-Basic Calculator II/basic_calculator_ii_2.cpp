class Solution {
public:
    int getPriority(char op) {
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
    }
    string transformToRPN(string s) {
        stringstream ss;
        stack<char> stk;
        for(int i = 0; i < s.length(); i ++){
            if(isdigit(s[i])) ss<<s[i];
            else if(s[i] == ' ') continue;
            else {
                //operators
                while(!stk.empty() && getPriority(stk.top()) >= getPriority(s[i])) {
                    ss<<" "<<stk.top();
                    stk.pop();
                }
                ss<<" ";
                stk.push(s[i]);
            }
        }
        while(!stk.empty()) {
            ss<<" "<<stk.top();
            stk.pop();
        }
        return ss.str();
    }
    
    int solveRPN(string s) {
        stringstream ss(s);
        string cur;
        stack<int> nums;
        while(getline(ss, cur, ' ')) {
            if(cur == "+" || cur == "-" || cur == "*" || cur == "/") {
                int operand_2 = nums.top();
                nums.pop();
                int operand_1 = nums.top();
                nums.pop();
                int res;
                switch(cur[0]) {
                    case '+': res = operand_1 + operand_2; break;
                    case '-': res = operand_1 - operand_2; break;
                    case '*': res = operand_1 * operand_2; break;
                    case '/': res = operand_1 / operand_2; break;
                }
                nums.push(res);
            } else if(cur == "") continue;
            else {
                nums.push(stoi(cur));
            }
        }
        return nums.top();
    }
    int calculate(string s) {
        string rpn = transformToRPN(s);
        // cout<<rpn;
        return solveRPN(rpn);
        // return 0;

    }
};
