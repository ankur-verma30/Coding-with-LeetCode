class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int smallestNumber=cost[0],n=cost.size();

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(cost[i]>=smallestNumber) ans[i]=smallestNumber;
            else if(smallestNumber>cost[i]){
                ans[i]=cost[i];
                smallestNumber=min(smallestNumber,cost[i]);
            }
        }

        return ans;
    }
};