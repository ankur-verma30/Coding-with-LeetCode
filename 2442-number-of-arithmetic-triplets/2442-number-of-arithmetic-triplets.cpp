class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size(),count=0;

        //optimised code some changes required
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++) mpp[nums[i]]=i;
   
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[i]>diff) break;
                if(nums[j]-nums[i]==diff){
                    if(mpp.find(nums[j]+diff)!=mpp.end()){
                        if(mpp[nums[j]+diff]>j) count++;
                    }
                }
            }
        }

        return count;
      
    }
};

/*
        //Brute force
         for(int i=0;i<n-2;i++){
             for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++ ){
                    if((nums[j]-nums[i]==diff) && (nums[k]-nums[j]==diff)) count++;
                }
            }
         }
*/