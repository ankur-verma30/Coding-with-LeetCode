class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        long long int high;
        int ans=1;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++ )
            high+=nums[i];

        while(low<=high){
            long long int mid=low+(high-low)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%mid==0) sum+=(nums[i]/mid);
                else sum+=(nums[i]/mid)+1;
            }
            if(sum>threshold) low=mid+1;
            else if(sum<=threshold){
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};