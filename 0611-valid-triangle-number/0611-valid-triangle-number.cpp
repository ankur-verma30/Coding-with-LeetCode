class Solution {
public:
    int triangleNumber(vector<int>& arr) {
         sort(arr.begin(),arr.end());
        int n=arr.size(),ans=0;
        for(int i=n-1;i>=2;i--){
            int j=0,k=i-1;
            while(j<k){
                int twoSideSum = arr[j]+arr[k];
                if(twoSideSum>arr[i]){
                    ans+=k-j;
                    k--;
                }
                else j++;
            }
        }
        return ans;
    }
};