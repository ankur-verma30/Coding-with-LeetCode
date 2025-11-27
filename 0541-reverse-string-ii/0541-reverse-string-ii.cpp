class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length(),i=0;
        if(n<=k) {
            reverse(s.begin(),s.end());
             return s;
        }

        while(i<n){
            if(i+k<=n){
                reverse(s.begin()+i,s.begin()+i+k);
            }
            else{
                reverse(s.begin()+i,s.end());
                break;
            }
            i+=2*k;
        }

        return s;
    }
};