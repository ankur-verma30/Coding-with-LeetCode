class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;

        int count=0;

        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]) continue;
            else{
                count+=abs(arr[i-1]-arr[i])+1;
                arr[i]=arr[i-1]+1;
            }
        }
        return count;
    }
};