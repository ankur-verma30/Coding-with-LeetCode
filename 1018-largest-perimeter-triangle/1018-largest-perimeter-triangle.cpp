class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), maxArea=0;

        for(int i=n-1;i>=2;i--){
            int secondSide=nums[i-1];
            int thirdSide=nums[i-2];
            int twoSideSum=secondSide+thirdSide;
            if(nums[i]<twoSideSum) maxArea=max(maxArea,(nums[i]+twoSideSum));
        }

        return maxArea;
    }
};