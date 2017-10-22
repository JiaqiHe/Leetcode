class Solution {
public:
    vector<string> res;
    void helper(string s, vector<string>& wordDict, string cur_res, int ptr){
        if(ptr >= s.length()){
            res.push_back(cur_res);
            return;
        } 
        for(int i = ptr; i < s.length(); i ++){
            string tmp = s.substr(ptr, i-ptr+1);
            vector<string>::iterator it;
            it = std::find(wordDict.begin(), wordDict.end(), tmp);
            if(it != wordDict.end()){
                //found
                string new_res = cur_res == ""? tmp : (cur_res + " " + tmp);
                helper(s, wordDict, new_res, i+1);
            }
        }
        return;
    } 
    
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
        if(s == "" || wordDict.empty() || wordBreakfortest(s, wordDict)==false) return res;
        string cur_res = "";
        helper(s, wordDict, cur_res, 0);
        return res;
    }
};
