class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0]>0)
            return nums.size();
        
      int count=0,pos=0,neg=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==0)
              count++;
        }
        
        int low=0,high=nums.size()-1;
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>0){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        if(ans!=0){
         pos=nums.size()-ans;
         neg=ans-count;
        }
        else{
            pos=0;
            neg=nums.size()-count;
        }
        
        
        if(count!=nums.size())
        return (pos>neg)?pos:neg;
        else 
            return 0;
    }
};