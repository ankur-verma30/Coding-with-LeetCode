//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        reverse(s.begin(),s.end());
        int carry=1;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int val=ch-'0';
            int sum=val+carry;
            int digit=sum%2;
            carry=sum/2;
            s[i]=digit+'0';
            
        }
        
        if(carry==1) s.push_back('1');
        
        while(s.back()=='0') s.pop_back();
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends