class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        char val=s[0];

        for(int i=0;i<s.length();i++){
            if(val!=s[i] && val!=(s[i]+32) && val!=(s[i]-32)){
                val=s[i];
                count++;
            }
        }
        return count;
    }
};