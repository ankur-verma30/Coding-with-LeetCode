class Solution {
    public int removeDuplicates(int[] nums) {
        int j=0, count=1;

        for(int i=1;i<nums.length;i++){
            if(nums[i]==nums[j]) continue;
            else{
                j++;
                count++;
                nums[j]=nums[i];
            }
        }
        return count;
    }
}