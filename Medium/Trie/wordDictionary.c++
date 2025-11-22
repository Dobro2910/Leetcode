class WordDictionary {
struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> children;

    TrieNode() {}
};

private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            auto it = temp->children.find(c);
            if (it != temp->children.end()) {
                temp = it->second;
            } else {
                temp->children[c] = new TrieNode();
                temp = temp->children[c];
            }
        }
        temp->isEnd = true;
    }
    
    bool search(const string& word, TrieNode* temp = nullptr) {
        if (!temp) temp = root;

        int n = word.size();

        for (int i = 0; i < n; ++i) {
            char c = word[i];

            if (c == '.') {
                // dot at last char
                if (i == n - 1) {
                    for (auto& p : temp->children)
                        if (p.second->isEnd) return true;
                    return false;
                }

                // PRECOMPUTE substring to avoid repeated creation
                string nextSub = word.substr(i + 1);

                for (auto& p : temp->children) {
                    if (search(nextSub, p.second))
                        return true;
                }
                return false;
            }

            // normal char — optimize lookups
            auto it = temp->children.find(c);
            if (it == temp->children.end()) return false;
            temp = it->second;
        }

        return temp->isEnd;
    }
};
