class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cur_len = -1;
        int i = 0;
        int cur_num = 0;
        while(i < words.size()) {
            while(i < words.size() && cur_len + words[i].length() + 1 <= maxWidth) {
                cur_len += (words[i++].length() + 1);
                cur_num++;
            }
            if(i != words.size() && cur_num > 1) {
                // when out, cur_len is maximized, we have (cur_num) words
                int spaces = maxWidth - (cur_len - (cur_num - 1));
                // these spaces have to be spread into cur_num-1 parts
                int residual = spaces%(cur_num-1);
                int base = spaces/(cur_num-1);
                // construct this line of text
                string cur = "";
                for(int j = i - cur_num; j < i; j ++) {
                    if(cur == "") {
                        cur += words[j];
                    }
                    else {
                        string blank(residual-- > 0 ? base + 1 : base, ' ');
                        cur += blank;
                        cur += words[j];
                    }
                }
                res.push_back(cur);
            } 
            else if(cur_num == 1 || i == words.size()) {
                string blank(maxWidth - cur_len, ' ');
                string cur = "";
                for(int j = i - cur_num; j < i; j ++) {
                    if(cur == "") {
                        cur += words[j];
                    }
                    else {
                        cur += (" " + words[j]);
                    }
                }
                cur += blank;
                res.push_back(cur);
            }
            cur_len = -1;
            cur_num = 0;
        }
        return res;
    }
};
