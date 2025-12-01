class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0],count=1,n=nums.size(),index=1;

        for(int i=1;i<n;i++){
            if(prev==nums[i]){
                if(count<=1){
                nums[index++]=nums[i];
                count++;
                }
                else continue;
            } 
            else {
                nums[index++]=nums[i];
                prev=nums[i];
                count=1;
            }

        }
        nums.resize(index);
        return index;
    }
};