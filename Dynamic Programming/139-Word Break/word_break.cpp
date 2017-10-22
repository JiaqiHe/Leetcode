class Solution {
public:
    bool find(string s, vector<string>& wordDict){
        for(int i = 0; i < wordDict.size(); i++){
            if(s == wordDict[i]) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
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
};
