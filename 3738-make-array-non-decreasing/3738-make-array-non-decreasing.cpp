class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();

        int largest=nums[0];
        vector<int>res;
        for(int i=1;i<n;i++){
            if(nums[i]>=largest){
                res.push_back(largest);
                largest=nums[i];
            }
        }

        res.push_back(largest);
        return res.size();

    }
};