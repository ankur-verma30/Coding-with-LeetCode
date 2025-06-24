class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            bool isFound=false;
            for(int j=0;j<n;j++){
                if(nums[j]!=key) continue;
                else if(abs(i-j)<=k) {
                    isFound=true; 
                    break;
                }  
            }
            if(isFound) ans.push_back(i);
        }

        return ans;
    }
};