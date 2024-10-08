class Solution {
public:
    int minSwaps(string s) {
        // using stack method
        stack<char> st;
        int n = s.length();
        if(n==2) return 0;

        for (int i = 0; i < n ; i++) {
            if ( !st.empty() && st.top()== '[' && s[i]==']' )
                st.pop();
             else 
                st.push(s[i]);
              
        }

        int unbalanced = st.size()/2;
        return (unbalanced+1) / 2;
    }
};