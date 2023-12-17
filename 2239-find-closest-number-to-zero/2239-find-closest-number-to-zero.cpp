class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int neg_max=INT_MIN;
        int pos_min=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0)
               neg_max=max(neg_max,nums[i]);
           else
           pos_min=min(pos_min,nums[i]);
            }

           if(abs(neg_max)==abs(pos_min))
           return pos_min;
           else if(abs(neg_max)>abs(pos_min))
           return pos_min;
           else if(neg_max==INT_MIN && pos_min)
           return pos_min;

           return neg_max;
    }
};