class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans=0l,count=0l;

        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                count++;
                ans+=count;
                continue;
            }
            else count=0;
        }

        return ans;
    }
}