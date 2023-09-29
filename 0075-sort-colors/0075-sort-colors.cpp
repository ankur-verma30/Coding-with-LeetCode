class Solution {
public:
    void sortColors(vector<int>& nums) {

        //can be sorted using better techniques
        for(int i=0;i<nums.size()-1;i++){
            for(int j=0;j<nums.size()-1-i;j++){
                if(nums[j]>nums[j+1]){
                    int tem=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=tem;
                }
            }
        }
    }
};