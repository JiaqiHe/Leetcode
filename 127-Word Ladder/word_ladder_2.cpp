class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bidirectional bfs
        unordered_set<string> list(wordList.begin(), wordList.end());
        unordered_set<string> begin;
        unordered_set<string> end;
        begin.insert(beginWord);
        end.insert(endWord);
        list.erase(beginWord);
        if(list.find(endWord) == list.end()) return 0;
        list.erase(endWord);
        
        int step = 2;
        while(!begin.empty()){
            unordered_set<string> nextlevel;
            for(string w : begin){
                string copy = w;
                int len = w.length();
                for(int i = 0; i < len; i ++){
                    for(char c = 'a'; c <= 'z'; c++){
                        w[i] = c;
                        if(end.find(w) != end.end()) return step;
                        
                        if(list.find(w) != list.end()){
                            nextlevel.insert(w);
                            list.erase(w);
                        }
                    }
                    w = copy;
                }
            }
            step++;
            if(nextlevel.size() == 0) return 0;
            if(nextlevel.size() < end.size()) begin = nextlevel;
            else{
                begin = end;
                end = nextlevel;
            }
        }
    }
};
