class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
         for(auto x:nums)
    result.push_back(x);
        for(auto x:nums)
    result.push_back(x);
         
         return result;
    }
};