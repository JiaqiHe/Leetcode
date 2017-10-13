class Solution {
public:
    void find(string word, unordered_set<string> &dict, queue<string> &toVisit){
        dict.erase(word);
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            for(int j = 0; j < 26; j ++){
                word[i] = 'a' + j;
                if(dict.find(word) != dict.end()){
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = c;
        }
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<string> toVisit;
        find(beginWord, wordDict, toVisit);
        int res = 2;
        while(!toVisit.empty()){
            int len = toVisit.size();
            for(int i = 0; i < len; i ++){
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord) return res;
                else find(word, wordDict, toVisit);
            }
            res++;
        }
        return 0;
    }
};

