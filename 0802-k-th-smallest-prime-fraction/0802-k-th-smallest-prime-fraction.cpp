class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n=arr.size();
        if(k==1) return {arr[0],arr[n-1]};
        priority_queue<pair<double,pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                pq.push({1.0*arr[i]/arr[j],{arr[i],arr[j]}});
                if(pq.size()>k) pq.pop();
            }
        }
        if(pq.size()==k) return {pq.top().second.first,pq.top().second.second};
        return {};
        
    }
};