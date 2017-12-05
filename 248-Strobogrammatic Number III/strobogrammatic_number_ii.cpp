class Solution {
public:
    bool ge(string a, string b){
        int lena = a.size();
        int lenb = b.size();
        if(lena > lenb) return true;
        else if(lena < lenb) return false;
        else{
            int i = 0;
            while(i < lena){
                if(a[i] < b[i]) return false;
                else if(a[i] > b[i]) return true;
                else i++;
            }
            return true;
        }
    }
    
    vector<string> dfs(string low, string high, int len, int cur){
        vector<string> res;
        if(cur == 0) return res = {""};
        if(cur == 1) return res = {"0", "1", "8"};
        vector<string> mid = dfs(low, high, len, cur-2);
        for(auto s : mid){
            if(cur != len) res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        return res;
    }
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        int len_l = low.length();
        int len_h = high.length();
        for(int i = min(len_l, len_h); i <= max(len_l, len_h); i ++){
            vector<string> c = dfs(low, high, i, i);
            for(int i = 0; i < c.size(); i ++){
                if(ge(c[i], low) && ge(high, c[i])) res++;
            }
        }
        return res;
    }
};
