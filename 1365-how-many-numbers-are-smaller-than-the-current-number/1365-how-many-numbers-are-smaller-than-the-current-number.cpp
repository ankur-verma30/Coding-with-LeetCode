class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        //Method 1 with T.C O(n^2) Brute Force
        // vector<int> result;
        // int len=nums.size();
        // for(int i=0;i<len;i++){
        //       int count=0;
        //     for(int j=0;j<len;j++ ){
        //     if(nums[i]>nums[j])
        //     count++;
        //     }
        //     result.push_back(count);
        // }
        // return result;

  //Method 2 With T.C. O(n) Optimised One
        vector<int> ans = nums;
        unordered_map<int, int> m;
        sort(ans.begin(), ans.end());
        for(int i=nums.size()-1; i>=0; i--)
            m[ans[i]] = i;
        for(int i=0; i<nums.size(); i++)
            nums[i] = m[nums[i]];
        return nums;

    }
};