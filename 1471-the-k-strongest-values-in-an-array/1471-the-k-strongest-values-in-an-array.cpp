class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ans;
        sort(arr.begin(), arr.end());//sort the array

        int n = arr.size(), med = arr[(n-1)/2];
        int  i=0, j=n-1;
        
        while(i<=j){
            if(abs(arr[i]-med) > abs(arr[j]-med))
                ans.push_back(arr[i++]);
            else
                ans.push_back(arr[j--]);
        }
        return {ans.begin(), ans.begin()+k};
    }
};