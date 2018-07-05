class Solution {
public:
    int kSimilarity(string A, string B) {
        if(A.length() != B.length()) return 0;
        // A -> B
        unordered_map<char, set<int>> dict;
        vector<bool> match(A.length(), false);
        set<int> unmatched;
        for(int i = 0; i < A.length(); i ++) {
            if(A[i] != B[i]) {
                dict[A[i]].insert(i);
                unmatched.insert(i);
            }
            else {
                match[i] = true;
            }
        }
        if(dict.empty()) return 0;
        int counter = 0;
        
        while(!unmatched.empty()) {
            bool didSwap = false;
            for(auto i : unmatched) {
                // expected char: B[i]
                // 想要找到一个char 它是B[i]，同时呢，它处在的位置应当是A[i]该呆的地方
                // 字符为B[i]的字符都在哪里呢？在dict[B[i]]里
                for(auto index : dict[B[i]]) {
                    if(B[index] == A[i]) {
                        // cout<<"first round: swaping "<<i<<" "<<index<<endl;
                        dict[A[index]].erase(index);
                        dict[A[i]].erase(i);
                        swap(A[i], A[index]);
                        unmatched.erase(i);
                        unmatched.erase(index);
                        didSwap = true;
                        counter++;
                        goto outOfLoop;
                    }
                }
            }
            outOfLoop:         
            if(!didSwap) {
                int i = *unmatched.begin();
                int res = INT_MAX;
                for(auto index : dict[B[i]]) {
                    swap(A[i], A[index]);
                    res = min(res, kSimilarity(A, B));
                    swap(A[i], A[index]);
                }
                counter += (res + 1);
                break;
            }
        }
        return counter;
    }
};
