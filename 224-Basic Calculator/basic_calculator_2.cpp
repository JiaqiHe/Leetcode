class Solution {
public:
    // transform infix expression to postfix expression (RPN)
    string transformToRPN(string s) {
        stringstream ss;
        stack<char> ops;
        for(int i = 0; i < s.length(); i ++){
            if(isdigit(s[i])) {
                ss<<s[i];
                continue;
            }
            if(s[i] == ' ') continue;
            if(s[i] == '(') ops.push(s[i]);
            else if(s[i] == ')') {
                while(!ops.empty() && ops.top() != '(') {
                    ss<<" "<<ops.top();
                    ops.pop();
                }
                ops.pop(); // pop out '('
            } else {
                while(!ops.empty() && ops.top() != '(') {
                    ss<<" "<<ops.top();
                    ops.pop();
                }
                ops.push(s[i]);
                ss<<" ";
            }
        }
        while(!ops.empty()) {
            ss<<" "<<ops.top();
            ops.pop();
        }
        return ss.str();
    }
    
    int solveRPN(string s) {
        stringstream ss(s);
        string cur;
        stack<int> stk;
        while(getline(ss, cur, ' ')) {
            if(cur == "+" || cur == "-") {
                int operand_2 = stk.top();
                stk.pop();
                int operand_1 = stk.top();
                stk.pop();
                stk.push(cur == "+" ? operand_1 + operand_2 : operand_1 - operand_2);
            } else {
                stk.push(stoi(cur));
            }
        }
        return stk.top();
    }
    int calculate(string s) {
        string rpn = transformToRPN(s);
        // cout<<rpn;
        // return 0;
        return solveRPN(rpn);
    }
};
