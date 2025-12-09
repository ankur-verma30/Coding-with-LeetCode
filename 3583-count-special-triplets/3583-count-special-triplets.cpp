class Solution {
public:
    int specialTriplets(vector<int>& nums) {
       unordered_map<int,int>validPair;
       unordered_map<int,int>leftVisited;

       int count=0,n=nums.size(),mod=1e9+7;

       for(int i=0;i<n;i++){
        if(nums[i]%2==0 && validPair.count(nums[i]/2)){
            int freq=validPair[nums[i]/2]%mod;
            count=(count%mod+freq%mod)%mod;
        }
        if(leftVisited.count(nums[i]*2)){
            int doubleFreq=leftVisited[nums[i]*2]%mod;
            validPair[nums[i]]=(validPair[nums[i]]%mod+doubleFreq%mod)%mod;
        }
        leftVisited[nums[i]]++;
       } 

       return count;
    }
};