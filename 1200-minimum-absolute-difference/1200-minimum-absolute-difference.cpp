class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<int,vector<vector<int>>>mp;
        int n=arr.size();

        sort(arr.begin(),arr.end());

        for(int i=1;i<n;i++){
            int diff=arr[i]-arr[i-1];
            mp[diff].push_back({arr[i-1],arr[i]});
        }

        auto it=mp.begin();
        vector<vector<int>>ans=it->second;

        sort(ans.begin(),ans.end());


        return ans;
        }
};