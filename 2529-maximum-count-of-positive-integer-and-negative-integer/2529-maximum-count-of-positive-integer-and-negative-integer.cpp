class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
         int low=0,high=nums.size()-1;
        int ans=0;
        int count=0,pos=0,neg=0;
        
        
        if(nums[0]>0)//if all numbers are positive
            return nums.size();
        
      
        for(int i=0;i<nums.size();i++){  //counting number of zeroes
          if(nums[i]==0)
              count++;
        }
        
     
        
        while(low<=high){         //applying binary search
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