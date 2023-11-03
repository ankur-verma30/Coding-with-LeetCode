class Solution {
public:
    int findMaxK(vector<int>& nums) {

        /* This is better approach 
        unordered_map<int,int>m;
        int mx=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(m.find(-num)!=m.end())
                mx=max(mx,abs(num));
            m[nums[i]]=nums[i];
        }
        return mx;
        */

        //This is optimized approach TC O(nlogn)  SC  O(1)
         sort(nums.begin(),nums.end());
         int left = 0, right = nums.size() - 1;
         int mx=-1;

        while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == 0) {
            mx = max(mx, abs(nums[left])); // Update maximum value
            left++;
            right--;
        } else if (sum > 0) 
            right--;
        else 
            left++;
        
        }
         return mx;
        }
};