class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp=nums;

        for(int i=0;i<n-1;i++){ //i=1
            for(int j=1;j<nums.size()-i;j++){ // j=1 --> j<4  1,2,3
                temp[j-1]=(temp[j-1]+temp[j])%10;
            }
            temp.resize(n-i-1);

        }

        return temp[0];
    }
};