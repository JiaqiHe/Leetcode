class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> dict(128, 0);
        int begin = 0, end = 0, len = 0, counter = 0;
        while(end < s.length()){
            if(dict[s[end++]]++ == 0){
                //new letter
                if(++counter <= 2) len = max(len, end - begin);
                else{
                    while(counter > 2){
                        if(--dict[s[begin++]] == 0) counter--;
                    }
                    len = max(len, end - begin);
                }
            }
            else{
                len = max(len, end - begin);
            }
        }
        return len;
    }
};
