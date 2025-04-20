class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();

        int largest = nums[0],count=1;
       
        for (int i = 1; i < n; i++) {
            if (nums[i] >= largest) {
                count++;
                largest = nums[i];
            }
        }

        return count;
    }
};