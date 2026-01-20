class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n=nums.length;

        int[] ans=new int[n];

        int negative=1,index=0,positive=0;

        while(index<n){
            if(nums[index]>0){
                ans[positive]=nums[index];
                positive+=2;
            }
            else{
                ans[negative]=nums[index];
                negative+=2;
            }
            index++;
        }

        return ans;

    }
}