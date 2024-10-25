class Trie {
    Trie* childrenNode[27];
    bool isEndsWith;

public:
    Trie() {
        isEndsWith = false;
        for (int i = 0; i < 27; i++)
            childrenNode[i] = NULL;
    }

    ~Trie() {
        for (int i = 0; i < 27; i++)
            delete childrenNode[i];
    }

    int getIndex(char ch) { return ch == '/' ? 26 : ch - 'a'; }

    void insertKey(const string& key) {
        Trie* curr = this;
        for (auto ch : key) {
            int index = getIndex(ch);
            if (curr->childrenNode[index] == NULL)
                curr->childrenNode[index] = new Trie();

            curr = curr->childrenNode[index];
        }
        curr->childrenNode[26] = new Trie();
        curr = curr->childrenNode[26];
        curr->isEndsWith = true;
    }

    bool searchKey(const string& folder) {
        Trie* curr = this;
        for (auto ch : folder) {
            if (curr->isEndsWith)
                return true;

            int index = getIndex(ch);
            if (curr->childrenNode[index] == NULL)
                return false;

            curr = curr->childrenNode[index];
        }
        return curr->isEndsWith;
    }
};
class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a.length() < b.length();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* root = new Trie();
        int n = folder.size();

        sort(folder.begin(), folder.end(), cmp);
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string str = folder[i];
            if (!root->searchKey(str)) {
                root->insertKey(str);
                ans.push_back(str);
            }
        }
        delete root;
        return ans;
    }
};