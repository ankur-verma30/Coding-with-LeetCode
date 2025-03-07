class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        vector<bool>isPresent(26,false);
        vector<int>lastOccurance(26,-1);

        int n=s.length();

        for(int i=0;i<n;i++) lastOccurance[s[i]-'a']=i;

        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(isPresent[idx]) continue;

            while(!ans.empty() && ch<ans.back() && i<lastOccurance[ans.back()-'a']){
                isPresent[ans.back()-'a']=false;
                ans.pop_back();
            } 
            isPresent[idx]=true;
            ans+=ch;
           
        }
       return ans; 
    }
};