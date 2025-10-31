class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>freq(100,0);
        vector<int>ans;


        for(const auto it:nums){
            if(freq[it]) ans.push_back(it);
            else freq[it]=1;

        }
        return ans;
    }
};