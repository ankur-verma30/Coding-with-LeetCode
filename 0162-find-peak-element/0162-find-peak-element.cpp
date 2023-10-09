class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len=nums.size(); //size of the array
        
       if(len==1) //for one element
           return 0;
        
        if(nums[len-1]>nums[len-2])//if peak is last element
            return len-1;
        
        if(nums[0]>nums[1])  //if peak is first element
            return 0;
        
        int low=1,high=len-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1] &&nums[mid]>nums[mid-1])
                return mid;
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1])
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};