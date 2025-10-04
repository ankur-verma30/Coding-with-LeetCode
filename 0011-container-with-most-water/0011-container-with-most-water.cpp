class Solution {
public:
    int maxArea(vector<int>& height) {
         int high=height.size();
        int i=0,j=high-1;
        int maxWater=0;

        while(i<j){
            int val=min(height[i],height[j]);
            maxWater=max(maxWater,val*(j-i));
            if(height[i]<height[j]) i++;
            else if(height[i]==height[j]){
                i++;
                j--;
            }
            else
            j--;
        }
        return maxWater;
    }
};