class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        
        Using ordered_map
        map<int,int,greater<int>>mp;

        for(int x:nums) mp[x]++;

        for(auto x:mp){
         k=k-x.second;
          if(k<=0) return x.first;
        }
        return 0;
        */
        
        //Using priority_queue
        
        priority_queue<int>pq;
        int res=0;
        
        for(int x:nums) pq.push(x);
        
        while(k--){
            res=pq.top();
            pq.pop();
        }
        return res;

    }
};