class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int Xor1=0,Xor2=0; 

       for(int i=0;i<nums.size();i++){
       Xor2=Xor2^nums[i];
       Xor1=Xor1^(i+1);
       }

       return Xor1^Xor2;
    }
};