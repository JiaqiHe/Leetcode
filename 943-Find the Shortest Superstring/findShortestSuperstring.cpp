class Solution {
public:
    // KMP algorithm
    // help find the boarder of the given string s
    //                s
    //   [=====_______________=====]
    //     |----> boarder <-----|
    //
    // to avoid duplicate computation, we added a hash map that saves the results to serve as a memorization space
    int KMP(string s, unordered_map<string, int>& memorization) {
        if(memorization.find(s) != memorization.end()) {
            return memorization[s];
        }
        
        vector<int> boarder(s.length(), 0);
        for(int i = 1; i < s.length(); i++) {
            int ptr = boarder[i - 1];
            while(ptr > 0 && s[ptr] != s[i]) {
                ptr = boarder[ptr - 1];
            }
            if(s[ptr] == s[i]) {
                ptr++;
            }
            boarder[i] = ptr;
        }
        memorization[s] = boarder.back();
        return boarder.back();
    }
    
    // find the shortest superstring
    // each iteration, merge two strings
    // the queue is served to store multiple possible cases in the iteration
    
    string shortestSuperstring(unordered_set<string>& dictionary) {
        unordered_map<string, int> memorization;
        queue<unordered_set<string>> q;
        q.push(dictionary);
        
        string res;
        while(!q.empty()) {
            unordered_set<string> dict = q.front();
            q.pop();
            if(dict.size() > 1) {
                int res = -1;
                vector<pair<string, string>> pairs;
                for(auto iter1 = dict.begin(); iter1 != dict.end(); iter1++) {
                    for(auto iter2 = dict.begin(); iter2 != dict.end(); iter2++) {
                        if(iter1 == iter2) continue;
                        int cur_boarder = KMP((*iter1) + (*iter2), memorization);
                        if(cur_boarder > res) {
                            res = cur_boarder;
                            pairs.clear();
                            pairs.push_back(make_pair(*iter1, *iter2));
                        }
                        else if(cur_boarder == res) {
                            pairs.push_back(make_pair(*iter1, *iter2));
                        }
                    }
                }
                for(auto p : pairs) {
                    unordered_set<string> cpy(dict);
                    cpy.insert(p.second + p.first.substr(res));
                    cpy.erase(p.first);
                    cpy.erase(p.second);
                    q.push(cpy);
                }
            }
            else {
                res = res == "" ? (*dict.begin()) : (res.length() < (*dict.begin()).length() ? res : (*dict.begin()));
            }
        }
        
        return res;
    }
    
    string shortestSuperstring(vector<string>& A) {
        unordered_set<string> dict(A.begin(), A.end());
        return shortestSuperstring(dict);

    }
};
