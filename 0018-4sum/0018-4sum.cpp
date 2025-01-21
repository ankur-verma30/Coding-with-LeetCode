class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<long long, int> mpp;
        int n = nums.size();
        set<vector<int>>ans;
        vector<vector<int>>res;

        for (int i = 0; i < n; i++)
            mpp[nums[i]] = i;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                     long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[k]);
                      long long complement = static_cast<long long>(target) - sum;
                    if (mpp.find(complement) != mpp.end()) {
                        int index = mpp[complement];
                        if (index != i && index != j && index != k) {
                            vector<int> temp{nums[i], nums[j], nums[k],
                                             nums[index]};
                                             sort(temp.begin(),temp.end());
                          ans.insert(temp);
                            
                        }
                    }
                }
            }
        }
        
        for(const auto it:ans) res.push_back(it);

        return res;
    }
};