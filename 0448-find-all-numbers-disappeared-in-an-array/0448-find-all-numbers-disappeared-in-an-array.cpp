class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    map<int,int> mp;
    vector<int> result;
    for (int num : nums) {
        mp[num]++;
    }
    for (int i = 1; i <= nums.size(); ++i) {
        if (mp.find(i) == mp.end()) {
            result.push_back(i);
        }
    }

    return result;
}
};