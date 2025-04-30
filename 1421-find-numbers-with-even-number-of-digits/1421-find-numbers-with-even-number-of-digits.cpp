class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;

        for(const auto &num:nums){
            int digit=floor(log10(num) + 1);
            if(digit%2==0) count++;
        }

        return count;
    }
};