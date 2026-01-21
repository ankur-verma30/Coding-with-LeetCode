class Solution {
    void swap(int a,int b,int[] nums){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;

    }

    void reverseArray(int startIndex,int endIndex,int[] nums){
            while(startIndex<endIndex){
                swap(startIndex,endIndex,nums);
                startIndex++;
                endIndex--;
            }
    }

    public void nextPermutation(int[] nums) {
        int n=nums.length, reverseIndex=-1;

        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                reverseIndex=i-1;
                break;
            }
        }

        int swapIndex=0;

        if (reverseIndex != -1) {
            for (int i = n - 1; i > reverseIndex; i--) {
                if (nums[i] > nums[reverseIndex]) {
                    swap(i, reverseIndex, nums);
                    break;
                }
            }
        }

        reverseArray(reverseIndex+1,n-1,nums);
    }
}