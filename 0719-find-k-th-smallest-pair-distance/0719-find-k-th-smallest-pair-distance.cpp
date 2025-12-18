class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        vector<int>freq((maxi-mini+1),0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(nums[i] - nums[j]);
                freq[distance]++;
            }
        }


        int sum = 0;
        for (int i = 0; i < maxi-mini+1; i++) {
            sum += freq[i];
            if (sum >= k)
                return i;
        }

        return -1;
    }
};