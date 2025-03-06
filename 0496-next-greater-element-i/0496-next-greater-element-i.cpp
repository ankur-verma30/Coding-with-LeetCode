class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n2=nums2.size();
        unordered_map<int,int>mpp;
        stack<int>st;

            for(int j=n2-1;j>=0;j--){
                while(!st.empty() && nums2[st.top()]<nums2[j]) st.pop();
                if(st.empty()) mpp[nums2[j]]=-1;
                else mpp[nums2[j]]=nums2[st.top()];    
                st.push(j);
            }

        for(auto num:nums1) ans.push_back(mpp[num]);
        
        return ans;
    }
};