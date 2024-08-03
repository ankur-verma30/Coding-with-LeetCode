//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
     static bool compare(const pair<int,int>a,const pair<int,int>b){
        return a.second<b.second;
    }
    
    int maxMeetings(int n,int start[],int end[]){
        
       vector<pair<int,int>>meeting;
       
       for(int i=0;i<n;i++){
           pair<int,int>temp={start[i],end[i]};
           meeting.push_back(temp);
       }
       
       sort(meeting.begin(),meeting.end(),compare);
       
       int count=1;
       int ansEnd=meeting[0].second;
       
       for(int i=1;i<n;i++){
           if(ansEnd<meeting[i].first){
               count++;
               ansEnd=meeting[i].second;
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends