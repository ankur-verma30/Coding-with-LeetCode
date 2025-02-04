class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int maxSum=0,n=arr.size(),sum=arr[0];

        for(int i=0;i<n-1;i++){
            maxSum=max(sum,maxSum);
            if(arr[i]<arr[i+1]) sum+=arr[i+1];
            else{
                sum=0;
                sum+=arr[i+1];
            }
        }
         maxSum=max(sum,maxSum);


        return maxSum;
    }
};