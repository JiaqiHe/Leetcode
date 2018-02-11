class Codec {
public:
    // Bencode: length of the content + delimiter + content
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i ++) {
            string cur = to_string(strs[i].length()) + "@" + strs[i];
            res += cur;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()) {
            int cur = 0;
            while(isdigit(s[i])) cur = cur * 10 + s[i++] - '0';
            res.push_back(s.substr(i + 1, cur));
            i += (cur + 1);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
