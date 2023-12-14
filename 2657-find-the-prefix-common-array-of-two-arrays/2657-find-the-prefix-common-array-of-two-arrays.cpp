class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>CommonArray;
         vector<int> hashArray(51,0);
        int count=0;

        for(int i=0;i<A.size();i++){
            if(hashArray[A[i]]<0)
                count++;
            hashArray[A[i]]++;
            if(hashArray[B[i]]>0)
                count++;
            hashArray[B[i]]--;
            CommonArray.push_back(count);
        }
        return CommonArray;
    }
};