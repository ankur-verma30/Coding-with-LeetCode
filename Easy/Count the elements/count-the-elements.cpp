//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int binarySearch(std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans + 1; 
}
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
            
          map<int, int> freqB;
    sort(b.begin(), b.end());
    std::vector<int> prefixFreq(b.size());

    prefixFreq[0] = b[0];
    for (int i = 1; i < b.size(); ++i) {
        prefixFreq[i] = prefixFreq[i - 1] + b[i];
    }
    
    std::vector<int> result;
    for (int i = 0; i < query.size(); ++i) {
        int x = a[query[i]];
        int count = binarySearch(b, x);
        result.push_back(count);
    }
    
    return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends