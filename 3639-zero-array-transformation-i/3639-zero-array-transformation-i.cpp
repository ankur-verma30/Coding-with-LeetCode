class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>difference(n,0);
        for(const auto query:queries){
            int start=query[0];
            int end=query[1];
            
            difference[start]-=1;
            if(end+1<n) difference[end+1]+=1;
        }

        for(int i=0;i<n;i++){
            if(i==0){
           nums[i]+=difference[i];
           if(nums[i]>0) return false;
           continue;
            }
            difference[i]+=difference[i-1];
            nums[i]+=difference[i];
           if(nums[i]>0) return false;
        }

        return  true;
    }
};