class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
          int n=nums.size(),xortotal=0;
        int total_subsets=1<<n;


        for(int i=0;i<(total_subsets);i++){
            int xorvalue=0;
            for(int j=0;j<n;j++){
               if(i &(1<<j)) xorvalue^=nums[j];
            }
            xortotal+=xorvalue;
        }

        return xortotal;
    }
};