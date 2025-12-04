class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0,n=nums.size();
        unordered_set<int>st;

        for(int right=0;right<n;right++){
            if(right-left>k) st.erase(nums[left++]);
            if(right-left<=k && st.count(nums[right])) return true;
            st.insert(nums[right]);
        }

        return false;
    }
};