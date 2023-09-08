class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->links[index]) {
                node->links[index] = new TrieNode();
            }
            node = node->links[index];
        }
        node->isEnd = true;
    }

    bool searchInNode(string word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && searchInNode(word, node->links[i], index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            if (node->links[idx]) {
                return searchInNode(word, node->links[idx], index + 1);
            } else {
                return false;
            }
        }
    }

    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};
