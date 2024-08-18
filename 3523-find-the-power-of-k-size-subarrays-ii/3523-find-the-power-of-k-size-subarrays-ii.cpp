class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>conse(n);
        vector<int>res(n-k+1);
    
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1) conse[i]=conse[i-1]+1;
            else conse[i]=0;
        }

        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<i-k+1) dq.pop_front();

            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();

            dq.push_back(i);

            if(i>=k-1){
                if(conse[i]>=k-1) res[i-k+1]=nums[dq.front()];
                else res[i-k+1]=-1;
            }
            
        }
        return res;
    }
};