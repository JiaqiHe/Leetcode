class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.length(), S.length());
        // left to right
        int last = INT_MIN;
        int ptr = 0;
        while(ptr < S.length()) {
            // find first char that is C
            while(ptr < S.length() && S[ptr] != C) ptr++;
            if(ptr >= S.length()) {
                // reach the end
                for(int i = last + 1; i < S.length(); i ++) {
                    res[i] = min(res[i], i - last);
                }
            }
            else {
                // found C
                if(last == INT_MIN) {
                    for(int i = 0; i <= ptr; i ++) {
                        res[i] = min(res[i], ptr - i);
                    }
                }
                else {
                    for(int i = last + 1; i <= ptr; i ++) {
                        res[i] = min(res[i], min(i - last, ptr - i));
                    }
                }
                last = ptr++;
            }
        }
        return res;
    }
};
