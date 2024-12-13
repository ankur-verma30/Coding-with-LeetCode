class Solution {
public:
    int solve(vector<int>temp,int x){
        int sum=0;
        unordered_map<int,int>mpp;
        for(const auto &it:temp){
            mpp[it]++;
            sum+=it;
        }
        int mapSize=mpp.size();
        if(mapSize<x) return sum;

        priority_queue<pair<int,int>>pq;
        for(const auto &[value,freq]:mpp){
            pq.push({freq,value});
        }

        sum=0;
        while(x--){
            auto  element=pq.top();
            pq.pop();
            int value=element.second;
            int freq=element.first;
            sum+=(value*freq);
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<=n-k;i++){
            vector<int>temp(nums.begin()+i,nums.begin()+i+k);
            int res=solve(temp,x);
            cout<<"Res value is "<<res<<endl;
            ans.push_back(res);
        }

        return ans;
    }
};