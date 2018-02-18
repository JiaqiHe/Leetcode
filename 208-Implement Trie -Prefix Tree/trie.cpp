class Trie {
private:
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> dict;
        TrieNode(): isEndOfWord(false) {}
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* root = this->root;
        for(int i = 0; i < word.length(); i ++) {
            if(root->dict.find(word[i]) == root->dict.end()) {
                // new character
                TrieNode* ch = new TrieNode();
                root->dict[word[i]] = ch;
            } 
            root = root->dict[word[i]];
        }
        root->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* root = this->root;
        for(int i = 0; i < word.length(); i ++) {
            if(root->dict.find(word[i]) == root->dict.end()) return false;
            root = root->dict[word[i]];
        }
        return root->isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* root = this->root;
        for(int i = 0; i < word.length(); i ++) {
            if(root->dict.find(word[i]) == root->dict.end()) return false;
            root = root->dict[word[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
