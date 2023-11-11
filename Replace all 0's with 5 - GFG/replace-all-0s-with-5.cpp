//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends


/*you are required to complete this method*/
int reverse(int n){
    int rv=0,rem=0;
    while(n!=0){
        rv=rv*10+n%10;
        n=n/10;
    }
    return rv;
}
int convertFive(int n) {
int rev=0;
bool flag=false;

 if(n<0){
     flag=true;
     n=abs(n);
 }
 
while(n!=0){
    int rem=n%10;
    if(rem==0)
    rem=5;
  rev=rev*10+rem;
  n=n/10;
}

int res=reverse(rev);

 if(flag==true)
 return res*-1;
 
 return res;
}