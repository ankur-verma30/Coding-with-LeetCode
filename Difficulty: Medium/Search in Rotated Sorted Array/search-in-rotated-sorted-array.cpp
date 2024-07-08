//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& A, int x) {
        // complete the function here
           int low = 0;
    int high = A.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(A[mid] ==x) return mid;
            
            if(A[low] == A[mid]) //handles duplicay or when low and mid at same point.
            low++;

            else if(A[low] <=A[mid])   // if left half sorted
            {
                if(x>=A[low] && x<A[mid] ) // checking if present in left sorted part
                high = mid-1;
                else
                low=mid+1;
            }
            
            else // if right half sorted A[low] >A[mid]
            {
                // checking if present in right half; 
                if(x>A[mid] && x<=A[high])  
                low=mid+1;
                
                else
                high = mid-1;
            }

        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends