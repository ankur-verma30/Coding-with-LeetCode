class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len=nums.size()/2;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        for(auto x:m){
            if(x.second==len)
                return x.first;
        }
        return 0;
    }
};