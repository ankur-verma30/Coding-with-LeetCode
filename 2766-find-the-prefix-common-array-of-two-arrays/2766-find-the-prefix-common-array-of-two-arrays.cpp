class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mpp;
        set<int>st;
        int n=A.size();

        vector<int>res;
        for(int i=0;i<n;i++){
            mpp[A[i]]++;
            if(mpp[A[i]]==2) st.insert(A[i]);
            mpp[B[i]]++;
            if(mpp[B[i]]==2) st.insert(B[i]);

            res.push_back((int)st.size());
        }

        return res;
    }
};