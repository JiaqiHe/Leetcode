class Solution {
public:
    unordered_map<char, string> pDict;
    unordered_map<string, char> sDict;
    
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, 0, str, 0);
    }
    
    bool dfs(string pattern, int i, string str, int j){
        int pLen = pattern.length();
        int sLen = str.length();
        if(i == pLen && j == sLen) return true;
        if(i == pLen || j == sLen) return false;
        bool toErase = false;
        for(int k = j; k < sLen; k ++){
            string cur = str.substr(j, k-j+1);
            if(pDict.find(pattern[i]) != pDict.end()){
                if(pDict[pattern[i]] != cur) continue;
            }
            else if(sDict.find(cur) != sDict.end()){
                if(sDict[cur] != pattern[i]) continue;
            }
            else{
                pDict[pattern[i]] = cur;
                sDict[cur] = pattern[i];
                toErase = true;
            }
            if(dfs(pattern, i+1, str, k+1)) return true;
            if(toErase){
                pDict.erase(pattern[i]);
                sDict.erase(cur);
            }
        }
        return false;
    }
};
