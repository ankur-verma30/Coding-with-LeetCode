class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        //Method 1

/*      vector<int> result;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            result.push_back(sum);
        }
        return result;
        */


        //Method 2

         for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        return nums;

            }
};