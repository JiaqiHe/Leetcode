class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        unordered_map<char, int> window;
        for(char c : t) dict[c]++;
        
        int counter = 0;//count the length that has been covered by s in T
        int len = INT_MAX;
        string res = "";
        for(int fast = 0, slow = 0; fast < s.length(); fast ++){
            if(dict.find(s[fast]) != dict.end()){
                //in string t
                if(++window[s[fast]] <= dict[s[fast]]) counter++;
            }
            
            if(counter == t.length()){
                //update slow
                while(dict.find(s[slow]) == dict.end() || window[s[slow]] > dict[s[slow]]) window[s[slow++]]--;
                //calculate length
                if(fast - slow + 1 < len){
                    len = fast - slow + 1;
                    res = s.substr(slow, len);
                }
            }
        }
        return res;
    }
};
