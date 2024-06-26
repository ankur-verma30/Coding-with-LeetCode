//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  int findClosest(vector<int>&arr, int low, int high, int x){
        while(low<=high){
            if(arr[high]<=x)
            return high;
            
            if(arr[low] >x)
            return low;
            
            int mid = low + (high-low)/2;
            
            if(arr[mid]<=x && arr[mid+1]>x)
            return mid;
            
            if(arr[mid] > x){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    
    vector<int> printKClosest(vector<int>arr, int n, int k, int x) {
        vector<int>ans(k,0);
        int m=0;
        
        int l = findClosest(arr, 0, n-1, x); //logn
        int r = l+1;
        
        if(arr[l]==x)
        l--;
        
        while(l>=0 && r<n && m<k){ //O(k)
            if(x - arr[l] < arr[r]-x){
                ans[m++] = arr[l];
                l--;
            }
            else{
                ans[m++] = arr[r];
                r++;
            }
        }
        while(m<k && l>=0){
           ans[m++] = arr[l];
                l--; 
        }
        while(m<k && r<n){
            ans[m++] = arr[r];
                r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends