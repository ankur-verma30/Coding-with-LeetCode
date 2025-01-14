class Solution {
public:
    unordered_map<string, bool> mpp;
    bool solve(string a, string b) {
       if(a==b)return true;
        if(a.length()!=b.length())return false;

        string key=a+"_"+b;
        if(mpp.find(key)!=mpp.end())return mpp[key];

        int n = a.length();
        bool flag = false;
        for (int i = 1; i < n; i++) {

           //swapping 
           bool swapped=solve(a.substr(0,i),b.substr(n-i,i))&&
           solve(a.substr(i,n-i),b.substr(0,n-i));

            //not swapped
            bool not_swapped=solve(a.substr(0,i),b.substr(0,i))&&
            solve(a.substr(i,n-i),b.substr(i,n-i));

            if (swapped || not_swapped) {
                flag = true;
                break;
            }
        }
        return mpp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
            mpp.clear();
        return solve(s1, s2);
    }
};