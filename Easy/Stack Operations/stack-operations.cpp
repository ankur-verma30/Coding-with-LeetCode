//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Geeks {
  public:
    // Function to insert element to stack
    void insert(stack<int>& st, int x) {
        st.push(x);
    }

    // Function to pop element from stack
    void remove(stack<int>& st) {
      if(!st.empty()) st.pop();
    }

    void headOf_Stack(stack<int>& st) {
        if(!st.empty())
      cout<< st.top()<<endl;
    }

    // Function to find the element in stack, print Yes,if found, else print No.
    void find(stack<int>& st, int val) {
        bool flag=false;
        stack<int>st2;
        
       while(!st.empty()){
           if(st.top()==val){
               flag=true;
           }
           st2.push(st.top());
           st.pop();
       }
       
       if(!flag) cout<<"No"<<endl;
       else cout<<"Yes"<<endl;
       
       
        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }
      
       
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        // Declaring stack of integers
        stack<int> st;

        int q;
        cin >> q;

        // Working with queries
        while (q--) {
            char ch;
            cin >> ch;
            Geeks obj;
            if (ch == 'i') {
                int x;
                cin >> x;
                obj.insert(st, x);
            }

            if (ch == 'r') {
                obj.remove(st);
            }

            if (ch == 'h') {
                obj.headOf_Stack(st);
            }
            if (ch == 'f') {
                int x;
                cin >> x;
                obj.find(st, x);
            }
        }
    }
}
// } Driver Code Ends