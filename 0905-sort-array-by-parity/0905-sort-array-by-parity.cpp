class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v;

        for(auto x:nums)
        if(x%2==0)
        v.push_back(x);

        for(auto x:nums)
        if(x%2!=0)
        v.push_back(x);

        return v;
    }
};