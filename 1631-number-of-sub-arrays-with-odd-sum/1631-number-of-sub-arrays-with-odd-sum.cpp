class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int oddCount=0,evenCount=1,totalCount=0,prefix=0;
        
        for(const auto &nums:arr){
           prefix+=nums;
           if(prefix%2==0){
            totalCount=(totalCount+oddCount)%MOD;
            evenCount++;
           }
           else{
            totalCount=(totalCount+evenCount)%MOD;
            oddCount++;
           }
        }

        return totalCount;
    }
};