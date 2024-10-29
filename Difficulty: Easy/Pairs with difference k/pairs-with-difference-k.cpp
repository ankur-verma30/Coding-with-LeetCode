//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        int count=0,n=arr.size();
        
        unordered_map<int,int>mpp;
         for (int i = 0; i < arr.size(); i++)  mpp[arr[i]]++; 


    for (int i = 0; i < arr.size(); i++) {
        int target1 = arr[i] + k;
        int target2 = arr[i] - k; 

        if (mpp.find(target1) != mpp.end()) {
            count += mpp[target1];
        }
        if (mpp.find(target2) != mpp.end()) {
            count += mpp[target2];
        }
        mpp[arr[i]]--;
    }
    return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends