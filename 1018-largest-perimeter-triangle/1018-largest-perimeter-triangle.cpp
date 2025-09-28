class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size(), maxArea=0;
        for(int i=0;i<n-2;i++){
            int secondSide=nums[i+1];
            int thirdSide=nums[i+2];
            int twoSideSum=secondSide+thirdSide;
            if(nums[i]<twoSideSum) maxArea=max(maxArea,(nums[i]+twoSideSum));
        }

        return maxArea;
    }
};