//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
         vector<vector<int>> adj(k);
    
    for (int i = 1; i < n; i++) {
        string str1 = dict[i - 1];
        string str2 = dict[i];
        
        for (int j = 0; j < min(str1.length(), str2.length()); j++) {
            if (str1[j] != str2[j]) {
                adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                break;
            }
        }
    }
    
    vector<int> indegree(k, 0);
    
    for (int i = 0; i < k; i++) {
        for (const auto &x : adj[i]) {
            indegree[x]++;
        }
    }
    
    queue<int> q;
    
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    string ans = "";
    
    while (!q.empty()) {
        int ch = q.front();
        q.pop();
        ans.push_back(ch + 'a');
        
        for (auto it : adj[ch]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    
    return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends