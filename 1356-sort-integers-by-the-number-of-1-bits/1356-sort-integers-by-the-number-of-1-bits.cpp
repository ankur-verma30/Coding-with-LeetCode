class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);

        for(int i=0;i<arr.size();i++)
        ans[i]= __builtin_popcount(arr[i])*10001+arr[i];

        sort(ans.begin(),ans.end());

          for (int i = 0; i < arr.size(); i++) 
            ans[i] %= 10001;

        return ans;
    }

};