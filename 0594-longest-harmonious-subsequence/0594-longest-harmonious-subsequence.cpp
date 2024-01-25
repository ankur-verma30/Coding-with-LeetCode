class Solution {
public:
    int findLHS(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 1, mx = 0;
        sort(nums.begin(), nums.end());

        while (j < len) {

            if (nums[j] - nums[i] == 1) 
                mx = max(mx, j - i + 1);
        
            while(nums[j]-nums[i]>1) i++;
            
            j++;
    }
                    
        return mx;
    }
};