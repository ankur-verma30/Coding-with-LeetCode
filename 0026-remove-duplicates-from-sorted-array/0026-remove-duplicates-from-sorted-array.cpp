class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int len=nums.size();
        int index=0;

        while(index<len-1){
            if(nums[index]==nums[index+1]){
                //Shift everything after i+1 one step left - O(n)

                for(int j=index+1;j<len-1;j++){
                    nums[j]=nums[j+1];
                }
                len--; // one fewer element
                // do no increment i: re-check nums[i] vs new nums[i+1]
            }
            else index++;
        }

        return len;
    }
};