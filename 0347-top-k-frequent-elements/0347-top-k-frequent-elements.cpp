struct compare{
bool operator()(const pair<int,int>&a,const pair<int,int>&b){
   if (a.first != b.first)  return a.first > b.first;     
   return a.second<b.second;
}
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;

        for(const auto &num:nums){
            mpp[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;

        for(const auto &[element,freq]:mpp){
            pq.push({freq,element});
            if(pq.size()>k) pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            auto temp=pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }

        return ans;
    }
};