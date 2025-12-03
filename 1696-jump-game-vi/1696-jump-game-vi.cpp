class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>dq;
        int right=0, left=0, n=nums.size();
        dq.push_back(0);

        for(right=1;right<n;right++){
            while(!dq.empty() && dq.front()<right-k) dq.pop_front();

            nums[right]+=nums[dq.front()];

            while(!dq.empty() && nums[dq.back()]<=nums[right])
            dq.pop_back();

            dq.push_back(right);
        }

        return nums[n-1];
    }
};