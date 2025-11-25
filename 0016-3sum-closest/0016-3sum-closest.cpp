class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = nums[0]+nums[1]+nums[2];

        int i = 0;

        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
        int j = i + 1, k = n - 1;

        while (j < k) {
            int currentSum=nums[i]+nums[j]+nums[k];
            if(abs(target-currentSum)<abs(target-closestSum)) closestSum = currentSum;
              if (currentSum < target) {
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                 }else if (currentSum > target)  k--;
                 else return target;
        }       
    }

        return closestSum;
    }
};