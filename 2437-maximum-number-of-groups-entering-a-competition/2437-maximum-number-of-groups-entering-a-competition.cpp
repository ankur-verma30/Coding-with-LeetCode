class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size(),low=0,high=1000,ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            if((mid*(mid+1))/2<=n){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }
};