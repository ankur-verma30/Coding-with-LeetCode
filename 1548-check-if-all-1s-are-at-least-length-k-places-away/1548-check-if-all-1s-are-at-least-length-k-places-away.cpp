class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        bool isFound = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1 && !isFound){
                isFound = true;
                count=0;
            }
            else if (nums[i] == 1 && isFound) {
                if (count < k)
                    return false;
                    count=0;
            } else count++;
    
        }
        return true;
    }
};