struct trieNode {
    bool isEnding;
    unordered_map<char, trieNode*> children;

    trieNode() : isEnding(false) {};

    ~trieNode() {
        for (auto& child : children) {
            delete child.second; // recursively delete child nodes
        }
    }
};

class Trie {
private:
    trieNode* root;

public:
    Trie() {
        root = new trieNode();
    }

    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        trieNode* node = root; // use a temp pointer to traverse

        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new trieNode(); // create if not exist
            }
            node = node->children[c]; // move down the trie
        }

        node->isEnding = true; // mark the end of the word
    }
    
    bool search(string word) {
        trieNode* node = root;

        for (char c : word) {
            if(node->children.find(c) == node->children.end()) {
                return false;
            } 

            node = node->children[c];
        }

        if (node->isEnding == true) {
            return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* node = root;

        for (char c : prefix) {
            if(node->children.find(c) == node->children.end()) {
                return false;
            }

            node = node->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */