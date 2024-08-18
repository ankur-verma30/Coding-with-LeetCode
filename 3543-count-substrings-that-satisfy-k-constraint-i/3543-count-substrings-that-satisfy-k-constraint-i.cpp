class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count=0;

        for(int i=0;i<s.length();i++){
            int ones=0,zeroes=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='0') zeroes++;
                else ones++;
            if(zeroes<=k || ones<=k) count++;
            }
        }

        return count;
    }
};