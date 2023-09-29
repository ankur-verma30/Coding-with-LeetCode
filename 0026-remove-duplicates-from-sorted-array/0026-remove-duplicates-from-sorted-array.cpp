class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
  int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};



/*

Sometimes things are good without using STL

 unordered_set<int> s;
   for(auto x:nums)
   s.insert(x);
   nums.clear();
   for(auto x:s)
   nums.push_back(x);
sort(nums.begin(),nums.end());
   return nums.size();
   */