class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
      vector<int>prefix(n,0);
      prefix[0]=arr[0];

      for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]^arr[i];
      }  

        vector<int>ans;
      for(int i=0;i<queries.size();i++){
        int first=queries[i][0];
        int second=queries[i][1];
        if(first==0) ans.push_back(prefix[second]);
        else{
            first=first-1;
            int num1=prefix[first];
            int num2=prefix[second];
            ans.push_back(num1^num2);
        }
      }

      return ans;
    }
};