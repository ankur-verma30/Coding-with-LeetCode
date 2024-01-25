class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,mx=0;
        int len=s.length();

        while(j<len){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                mx=max(mx,j-i+1);
             
            }
            if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
              
            }
            j++;
           
        }
        return mx;
    }
};