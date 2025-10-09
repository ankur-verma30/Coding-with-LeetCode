class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&adj, char curr_ch, vector<int>&visited){
        visited[curr_ch-'a']=1;
        char minChar=curr_ch;

        for(char &ch: adj[curr_ch]){
            if(visited[ch-'a']==0){
            minChar=min(minChar,dfs(adj,ch,visited));
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int len=s1.length();

        unordered_map<char,vector<char>>adj;

        for(int i=0;i<len;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        string result;
        for(int i=0;i<baseStr.length();i++){
            char ch=baseStr[i];
            vector<int> visited(26,0);
            char minChar=dfs(adj,ch,visited);
            result.push_back(minChar);
        }

        return result;
    }
};