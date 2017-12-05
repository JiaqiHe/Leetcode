class Solution {
public:
    string multiply(string num1, string num2) {
        string output;
        int len1 = num1.length();
        int len2 = num2.length();
        if(len1 == 0 || len2 == 0) return "0";
        vector<int> res(len1+len2, 0);
        int carry = 0;
        for(int i = 0; i < len1; i ++){
            int a = num1[len1-1-i] - '0';
            for(int j = 0; j < len2; j ++){
                int b = num2[len2-1-j] - '0';
                int mul = a * b + carry + res[i+j];
                res[i+j] = mul%10;
                carry = mul/10;
            }
            if(carry > 0) res[i+len2] += carry;
            carry = 0;
        }
        int top = len1 + len2 - 1;
        while(top >= 0 && res[top] == 0) top--;
        if(top < 0) return "0";
        while(top >= 0) output += ('0' + res[top--]);
        return output;
    }
};
