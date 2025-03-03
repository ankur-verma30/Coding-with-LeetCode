class Solution {
public:
    int partitionString(string s) {
        int n=s.length(),count=0;

        set<char>st;
        for(int i=0;i<n;i++){
            if(st.count(s[i])<1){
                st.insert(s[i]);
            }
            else{
                st.clear();
                count++;
                st.insert(s[i]);
            }
        }

        if(!s.empty()) count++;

        return count;
    }
};