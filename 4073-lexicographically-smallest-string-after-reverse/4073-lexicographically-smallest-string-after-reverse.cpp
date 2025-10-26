class Solution {
public:
    string lexSmallest(string s) {
        int n=s.length();
        string ans=s;

        for(int i=0;i<n;i++){
             string prefix = s.substr(0, i + 1);
            reverse(prefix.begin(), prefix.end());
            string remPrefix = s.substr(i + 1);
            string temp1 = prefix + remPrefix;
            ans = min(ans, temp1);

            string suffix = s.substr(n - i - 1);
            reverse(suffix.begin(), suffix.end());
            string remSuffix = s.substr(0, n - i - 1);
            string temp2 = remSuffix + suffix;
            ans = min(ans, temp2);

        }

return ans;

    }
};