class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> dict;
        TrieNode() {
            dict.resize(26, NULL);
        }
    };
    
    void addWord(string word, TrieNode* root, int &count) {
        int ptr = 0;
        bool covered = true;
        while(ptr < word.length()) {
            if(root->dict[word[ptr] - 'a'] != NULL) {
                // already has that char
                root = root->dict[word[ptr] - 'a'];
            }
            else {
                covered = false;
                TrieNode* newNode = new TrieNode();
                root->dict[word[ptr] - 'a'] = newNode;
                root = newNode;
            }
            ptr++;
        }
        if(!covered) count += word.length() + 1;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) { 
            if(a.length() != b.length()) return a.length() > b.length();
            else return a < b;
        });
        TrieNode *root = new TrieNode();
        int count = 0;
        for(auto &word : words) {
            reverse(word.begin(), word.end());
            addWord(word, root, count);
        }
        return count;
    }
};
