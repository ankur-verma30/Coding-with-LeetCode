class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count=0,sum=0;

        for(auto x:nums){
            sum+=x;
            if(sum==0) count++;
        }
        return count;
    }
};