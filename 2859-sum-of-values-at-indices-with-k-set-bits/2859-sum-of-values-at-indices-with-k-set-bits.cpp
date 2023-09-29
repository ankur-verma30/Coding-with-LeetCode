class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
         
 int total_sum = 0;

    auto countSetBits = [](int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    };

    for (int i = 0; i < nums.size(); i++) {
        if (countSetBits(i) == k) {
            total_sum += nums[i];
        }
    }
    
    return total_sum; 
    }
};