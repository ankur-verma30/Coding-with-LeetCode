class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len=nums.size()/3;
       unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        nums.clear();
        for(auto x:mp){
            if(x.second>len)
                nums.push_back(x.first);
            
        }
        return nums;
            
    }
};