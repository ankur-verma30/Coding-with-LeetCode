class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);

        for(int i=0;i<arr.size();i++)
        ans[i]=CountSetBits(arr[i])*10001+arr[i];

        sort(ans.begin(),ans.end());

          for (int i = 0; i < arr.size(); i++) 
            ans[i] %= 10001;

        return ans;
    }

    int CountSetBits(int n){
        int count=0;
        while(n!=0){
            count+=(n&1);
            n=n>>1;
    }
        return count;
    }

};