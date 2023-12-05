class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        bool value=false;

        for(int i=0;i<magazine.length();i++)
            mp[magazine[i]]++;

            
        for(int i=0;i<ransomNote.length();i++){
            if(mp[ransomNote[i]]){
                mp[ransomNote[i]]--;
                value=true;
            }  
            else{
                value=false;
                break;
            }     
        }

        return value;
    }
};