class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int swapIndex = -1,n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                swapIndex = i;
                break;
            }
        }
            if(swapIndex!=-1){
            for(int i=n-1;i>=swapIndex;i--){
            if (nums[i] > nums[swapIndex] ) {
              swap(nums[i],nums[swapIndex]);
                break;
            }
        }
            }
    
    if (swapIndex != -1) reverse(nums.begin() + swapIndex+1, nums.end());
    else reverse(nums.begin(), nums.end());
}
};