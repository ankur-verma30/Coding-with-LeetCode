class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>count;
        int ans=0;
    int len=nums.size();
        for(int i=0;i<len;i++){
            count[nums[i]]++;
        }
        for(auto x: count){
            if(x.second>len/2)
            return x.first;

        }
        return 0;
    }
};