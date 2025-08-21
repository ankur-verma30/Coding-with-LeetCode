class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,count=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[j]) continue;
            else{
                j++;
                count++;
                nums[j]=nums[i];
            }
        }

        nums.resize(count);
        return count;
    }
};