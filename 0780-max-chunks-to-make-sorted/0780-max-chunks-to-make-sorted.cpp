class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        for(int i= 0;i<arr.size();i++){
            //if the array is in ascending sorted order
            if(st.empty() || st.top()< arr[i]) st.push(arr[i]);  
            else 
            {
                //get the top elemet
               int maxEl = st.top();
                while(!st.empty() && st.top()> arr[i]) st.pop();
                st.push(maxEl);
            }
        }
        return (int)st.size();
    }
};