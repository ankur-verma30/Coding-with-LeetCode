struct Node{
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']; }

    Node* get(char ch){
        return links[ch-'a']; }

    void put(char ch,Node *node){
        links[ch-'a']=node; }

    void SetEnd(){flag=true; }

    bool IsEnd(){ return flag; }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root=new Node();
    }

    void insert(string words){
        Node *node=root;

        for(int i=0;i<words.length();i++){
            if(!node->containsKey(words[i])){
                node->put(words[i],new Node());
            }
            node=node->get(words[i]);
        }
        node->SetEnd();
    }

    bool CheckIfPrefixExist(string words){
        bool fl=true;
        Node *node=root;
        for(int i=0;i<words.length();i++){
            if(node->containsKey(words[i])){
                node=node->get(words[i]);
                if(node->IsEnd()==false) return false;
            }
            else return false;
        }
        return true;
    }


};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto &it: words)
        trie.insert(it);

        string longest="";

        for(auto &it: words){
            if(trie.CheckIfPrefixExist(it)){
                if(it.length()>longest.length()) longest=it;
                else if(it.length()==longest.length() && it<longest) longest=it;
            }
        }

        return longest;    
    }
};