class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        int mx=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(m.find(-num)!=m.end())
                mx=max(mx,abs(num));

            m[nums[i]]=nums[i];

        }
        return mx;

    }
};