class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length(), operations1 = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='0') continue;
            if(s[i]=='X'){
                operations1++;
                i+=2;
            }
        }

        return operations1;
    }
};