class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int orValue=0;

        for(int num:nums){
            if(num%2==0) orValue|=num;
        }

        return orValue;
    }
};