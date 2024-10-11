class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};
class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (auto& c : word) {
            if (curr->children[c - 'a'] == NULL) {
                TrieNode* newNode = new TrieNode();
                curr->children[c - 'a'] = newNode;
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) { return searchHelper(root, word, 0); }

    bool searchHelper(TrieNode* node, string word, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL) {
                    if (searchHelper(node->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }

        if (node->children[word[index] - 'a'] == NULL) {
            return false;
        }

        return searchHelper(node->children[word[index] - 'a'], word, index + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */