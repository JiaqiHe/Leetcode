class Solution {
public:
    void dfs(string num, int target, int index, vector<string> &res, int cur, int last, char op, string exp){
        if(index == num.length() && cur == target){
            res.push_back(exp);
            return;
        }
        if(index >= num.length()) return;
        for(int i = index; i < num.length(); i ++){
            int n = stol(num.substr(index, i-index+1));
            if(to_string(n).length() != i-index+1) continue;
            string temp = num.substr(index, i-index+1);
            //case 1: "+"
            dfs(num, target, i+1, res, cur+n, n, '+', exp+"+"+temp);
            //case 2: "-"
            dfs(num, target, i+1, res, cur-n, n, '-', exp+"-"+temp);
            //case 3: "*"
            dfs(num, target, i+1, res, op=='+'? cur-last+last*n : (op=='-'? cur+last-last*n : cur*n), last*n, op, exp+"*"+temp);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) return res;
        for(int i = 0; i < num.length(); i ++){
            int n = stol(num.substr(0, i+1));
            if(to_string(n).length() != i+1) continue;
            string exp = num.substr(0, i+1);
            dfs(num, target, i+1, res, n, n, '#', exp);
        }
        return res;
    }
};
