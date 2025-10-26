class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int k=(n%2)? (n/2)+1 : n/2;
        priority_queue<int>pq;

        for(auto it:nums){
            int digit=abs(it);
            pq.push(digit);
        }


        long long ans=0;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            if(k>0) ans+=(top*top);
            else if(k<=0) ans-=(top*top);
            k--;
            
        }

        return ans;
    }
};