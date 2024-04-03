class Solution {
public:
    string reverseStr(string s, int k) {
        int len=s.length();
        int right=0;

        while(right<len){
            if(len-right>=2*k) reverse(s.begin()+right,s.begin()+right+k);

            if(len-right<2*k && len-right>=k) reverse(s.begin()+right,s.begin()+right+k);

            if(len-right<k) reverse(s.begin()+right,s.end());
            right+=2*k;
        }

        return s;
    }
};