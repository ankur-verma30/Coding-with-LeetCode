class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> result;
       long  long int squares=0;
       for(int i=0;i<nums.size();i++){
       squares=pow(nums[i],2);
       result.push_back(squares);
       }
       sort(result.begin(),result.end());
       return result;

    }
};