class Solution {
    public int sumOfSquares(int[] nums) {
        int sum=0, n=nums.length;

        for(int i=0;i<n;i++){
            sum+=(n%(i+1)==0 ? nums[i]*nums[i]:0); 
        }

        return sum;
    }
}