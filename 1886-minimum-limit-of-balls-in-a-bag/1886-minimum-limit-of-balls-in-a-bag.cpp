class Solution {
public:
  bool isPossible(vector<int>&nums, int maxBallsAllowed, int maxOperations){
        int operations=0;
        for(int num : nums){
            if(num > maxBallsAllowed){
                int bags = (int)ceil(num / (double) maxBallsAllowed);
                operations+=bags-1;
            }
            if(operations > maxOperations)  return false; 
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
         int high=*max_element(nums.begin(),nums.end());

        int low=1,res=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(nums,mid,maxOperations)){
                res = mid;
                high = mid-1;
            }else low = mid+1;  
        }

        return res; 
    }
};