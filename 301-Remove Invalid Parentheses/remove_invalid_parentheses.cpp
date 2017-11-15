class Solution {
public:
    void remove(string s, vector<string> &res, int idx, int last, char ch){
        int counter = 0;
        for(int i = idx; i < s.length(); i ++){
            if(s[i] == '(' || s[i] == ')') s[i] == ch? counter--:counter++;
            if(counter >= 0) continue; //如果没啥问题， 就直接从这里跳到下一位字符了，不会往下看
            else {
                for(int j = last; j <= i; j ++){
                    if(s[j] == ch && (j == last || s[j-1] != ch)){
                        remove(s.substr(0,j)+s.substr(j+1), res, i, j, ch);
                    }
                }
            }
            return; //very important!!!!正是因为所有修改之后的情况都会经过这里，但是呢 我们并不希望这种做了一半的情况继续做下去。直接用return将它们终止
        }
        reverse(s.begin(), s.end());
        if(ch == ')') remove(s, res, 0, 0, '(');
        else res.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(s, res, 0, 0, ')');
        return res;
    }
};
