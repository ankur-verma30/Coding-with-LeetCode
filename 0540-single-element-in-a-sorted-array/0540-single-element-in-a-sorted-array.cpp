class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len=nums.size();
        
        if(len==1)//edge cases 1
            return nums[0];
        
        if(nums[0]!=nums[1]) //edge case 2
            return nums[0];
        
        if(nums[len-1]!=nums[len-2]) //edge case 3
            return nums[len-1];
        
        int low=1,high=len-2;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if((nums[mid]!=nums[mid+1] )&&(nums[mid]!=nums[mid-1]))
                return nums[mid];
            if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2!=0 &&(nums[mid]==nums[mid-1])))
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};