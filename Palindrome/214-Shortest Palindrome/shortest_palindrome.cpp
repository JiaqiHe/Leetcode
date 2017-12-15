class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string l = s + "$" + r;
        vector<int> p(l.length(), 0);
        for(int i = 1; i < l.length(); i ++){
            int j = p[i-1];
            while(j > 0 && l[j] != l[i]) j = p[j-1];
            if(l[j] == l[i]) j ++;
            p[i] = j;
        }
        return r.substr(0, r.length() - p[l.length() - 1]) + s;
    }
};
