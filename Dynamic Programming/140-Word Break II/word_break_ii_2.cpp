class Solution {
public:
    bool find(string s, vector<string>& wordDict){
    for(int i = 0; i < wordDict.size(); i++){
        if(s == wordDict[i]) return true;
    }
    return false;
    }
    bool wordBreakfortest(string s, vector<string>& wordDict) {
        if(wordDict.empty()) return false;
        vector<int> valid;
        valid.push_back(-1);
        for(int i = 0; i < s.length(); i++){
            bool cur = find(s.substr(0,i+1), wordDict);
            if(cur) valid.push_back(i);
            else{
                int ptr = valid.size()-1;
                while(ptr>=1){
                    int temp = valid[ptr--];
                    if(find(s.substr(temp+1, i-temp),wordDict)){
                        valid.push_back(i);
                        break;
                    }
                }
            }
        }
        return valid.back()==s.length()-1;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(s == "" || wordDict.empty() || wordBreakfortest(s, wordDict)==false) return res;        
        vector<vector<string>> dp(s.length(),vector<string>());
        vector<int> found;
        for(int i = 0; i < s.length(); i ++){
            bool have_found = false;
            for(int j = 0; j < found.size(); j ++){
                int idx = found[j];
                string str_to_find = s.substr(idx+1, i-idx);
                vector<string>::iterator it1;
                it1 = std::find(wordDict.begin(), wordDict.end(), str_to_find);
                if(it1 != wordDict.end()){
                    //found
                    have_found = true;
                    for(int k = 0; k < dp[idx].size(); k ++){
                        dp[i].push_back(dp[idx][k]+" "+str_to_find);
                    }
                }
            }
            string cur_str = s.substr(0, i+1);
            vector<string>::iterator it;
            it = std::find(wordDict.begin(), wordDict.end(), cur_str);
            if(it != wordDict.end()){
                have_found = true;
                dp[i].push_back(cur_str);
            } 
            if(have_found) found.push_back(i);
        }
        return dp[s.length()-1];
    }
};
