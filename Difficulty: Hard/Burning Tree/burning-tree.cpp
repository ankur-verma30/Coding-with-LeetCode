//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  Node * markParent(Node* root,unordered_map<Node*, Node*>& parent_track,int start) {
        queue<Node*> pq;
        Node *res;
        pq.push(root);
        while (!pq.empty()) {
            Node* current = pq.front();
            if(current->data==start) res=current;
            pq.pop();
            if (current->left) {
                parent_track[current->left] = current;
                pq.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                pq.push(current->right);
            }
        }
        return res;
  }
  
  int findMaxDistance(unordered_map<Node *,Node *>&parent_track,Node *ans){
        queue<Node*> pq;
       unordered_map<Node*, bool> visited;
        pq.push(ans);
        int maxi=0;
        visited[ans] = true;
        int curr_level = 0;
        while (!pq.empty()) {
            int size = pq.size();
            int fl=0;

            for (int i = 0; i < size; i++) {
                Node* current = pq.front();
                pq.pop();
                if (current->left && !visited[current->left]) {
                    fl=1;
                    pq.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    fl=1;
                    pq.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    fl=1;
                    pq.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            if(fl) maxi++;
        }
        return maxi;
       
  }
  
    int minTime(Node* root, int target) 
    {
        unordered_map<Node *,Node *>parent_track;
        Node *ans=markParent(root,parent_track,target);
        int maxi=findMaxDistance(parent_track,ans);
        return maxi;
       
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends