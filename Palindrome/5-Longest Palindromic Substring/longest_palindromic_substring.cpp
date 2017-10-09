class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int curmax = 0;
        string res;
        for(int i = 0; i < n; i++){
            for(int j = 0; i+j<n && i-j>=0 && s[i-j] == s[i+j]; j++){
                if(2*j + 1 > curmax){
                    curmax = 2*j+1;
                    res = s.substr(i-j, 2*j+1);
                }
            }
            for(int j = 0; i+j<n && i-1-j>=0 && s[i-1-j] == s[i+j]; j++){
                if(2*j + 2 > curmax){
                    curmax = 2*j+2;
                    res = s.substr(i-1-j, 2*j+2);
                }
            }
        }
        return res;
    }
};
