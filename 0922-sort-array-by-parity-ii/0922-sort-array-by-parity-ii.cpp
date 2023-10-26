class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
      stack<int> even,odd;
      for(int i=0;i<nums.size();i++){
          if(nums[i]%2==0)
          even.push(nums[i]);
          else
          odd.push(nums[i]);
      }

          nums.clear();

          while(!even.empty() && !odd.empty()){
              nums.push_back(even.top());
              even.pop();
              nums.push_back(odd.top());
              odd.pop();
          }

          return nums;
      }
};