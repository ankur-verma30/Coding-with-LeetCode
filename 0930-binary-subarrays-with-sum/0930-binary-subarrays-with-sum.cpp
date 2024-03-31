class Solution {
public:
    int numSumEqualToGoal(vector<int>&nums,int goal){

        if(goal<0) return 0;

        int left=0,right=0,count=0,sum=0;
        int size=nums.size();
        while(right<size){
            sum+=nums[right];
            
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (numSumEqualToGoal(nums,goal)-numSumEqualToGoal(nums,goal-1));
    }
};