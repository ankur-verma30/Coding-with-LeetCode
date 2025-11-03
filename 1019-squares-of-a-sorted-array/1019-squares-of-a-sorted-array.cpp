class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        int left=0,right=len-1;

        vector<int>ans(len,0);

        for(int i=len-1;i>=0;i--){
            int leftSquare=nums[left]*nums[left];
            int rightSquare=nums[right]*nums[right];
            if(leftSquare>rightSquare){
                ans[i]=leftSquare;
                left++;
            }
            else{
                ans[i]=rightSquare;
                right--;
            }
        }

        return ans;
    }
};