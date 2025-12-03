class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        int right=0,left=0,n=nums.size();
        for(right=0;right<n;right++){
            while(!dq.empty() && nums[dq.back()]<nums[right])
            dq.pop_back();

            dq.push_back(right);
            while(dq.front()<left) dq.pop_front();

            if(right-left+1==k){
                ans.push_back(nums[dq.front()]);
                left++;
            }
            
        }

        return ans;
    }
};