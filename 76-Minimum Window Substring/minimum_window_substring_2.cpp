class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dict(128,0);
        for(auto c : t) dict[c]++;
        int counter = t.length(), begin = 0, end = 0, len = INT_MAX;
        string res = "";
        while(end < s.length()){
            if(dict[s[end++]]-->0) counter--;
            while(counter == 0){
                if(end - begin < len){
                    len = end - begin;
                    res = s.substr(begin, len);
                }
                if(dict[s[begin++]]++ == 0) counter++;
            }
        }
        return res;
    }
};
