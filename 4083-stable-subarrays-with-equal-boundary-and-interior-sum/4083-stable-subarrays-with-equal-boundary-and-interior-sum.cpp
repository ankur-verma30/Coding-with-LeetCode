class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long ans = 0;
        int n = capacity.size();
        vector<long long> prefix(n, 0);
        prefix[0] = capacity[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + capacity[i];
        }

        map<pair<int,long long>,int> mp;
        for(int i=n-1;i>=0;i--){
            ans+=mp[{capacity[i],prefix[i]+2*capacity[i]}];
            //delaying the input in the map to maintain size of 3
            if(i+1<n) mp[{capacity[i+1],prefix[i+1]}]++;
        }

    return ans;
    }
};
