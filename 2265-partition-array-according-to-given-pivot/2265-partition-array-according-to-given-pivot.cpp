class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();

        vector<int>ans(n);
        int low=0,high=n-1;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                ans[low]=nums[i];
                low++;
            }
            if(nums[j]>pivot){
                ans[high]=nums[j];
                high--;
            }
        }

        while(low<=high){
            ans[low]=pivot;
            low++;
        }

        return ans;
    }
};