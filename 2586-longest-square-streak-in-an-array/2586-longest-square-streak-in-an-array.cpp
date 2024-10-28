class Solution {
public:
    bool isSqrtN(int n){
        int sqrtn=sqrt(n);
        return sqrtn*sqrtn==n;
    }
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());

      
        for(int i=0;i<nums.size();i++){
            if(isSqrtN(nums[i])){
                int val=sqrt(nums[i]);
                if(mpp.find(val)!=mpp.end()){
                    int count=mpp[val];
                    mpp[nums[i]]=count+1;
                }
                else mpp[nums[i]]=1;
            }
            else mpp[nums[i]]=1;
        }

        int maxCount=-1;
        for(auto x:mpp) maxCount=max(maxCount,x.second);

        return maxCount==1?-1:maxCount;

    }
};