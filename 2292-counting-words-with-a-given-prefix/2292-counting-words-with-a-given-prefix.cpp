class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    int count;
    TrieNode() : count(0) {}
};

class Trie {
private: 
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *curr = root;
        for(char c: word) {
            if(!curr->children[c]) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->count++;
        }
    }

    int count(string pref) {
        TrieNode *curr = root;
        for(char c: pref) {
            if(!curr->children[c]) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for(auto word: words) {
            trie.insert(word);
        }
        return trie.count(pref);
    }
};