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
class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
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

    bool search(string word) {
        TrieNode *curr=root;
        for(auto &c:word){
            if(curr->children[c-'a']==NULL) return false;
            curr=curr->children[c-'a'];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(auto &c:prefix){
            if(curr->children[c-'a']==NULL) return false;
            curr=curr->children[c-'a'];
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