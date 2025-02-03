class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incCount = 1, maxAns = 1, maxDec = 0, decCount = 1;

        if (nums.size() == 1)
            return 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]){
                incCount++;
                decCount=1;
            }
                
            else if (nums[i - 1] > nums[i]){
                  decCount++;
                  incCount=1;
            }
              
            else {
                incCount = 1;
                decCount = 1;
            }
            maxAns = max(maxAns,max(incCount, decCount));
        }
        return maxAns;
    }
};