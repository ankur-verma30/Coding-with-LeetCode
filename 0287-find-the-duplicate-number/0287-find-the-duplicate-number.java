class Solution {
    public int findDuplicate(int[] nums) {
         int n=nums.length;
       int low=1,high =n-1,ans=0;

       while(low<=high){
        int mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid) count++;
        }
        if(count<=mid) low=mid+1;
        else{
            ans=mid;
            high=mid-1;
        }
       }

       return ans;
    }
}