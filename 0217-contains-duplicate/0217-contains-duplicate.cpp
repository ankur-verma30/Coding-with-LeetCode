class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      /* 
      Method 1
       unordered_map<int,int>count;
       for(int i=0;i<nums.size();i++){
           count[nums[i]]++;
       }
       for(auto x: count){
           if(x.second>=2)
           return true;
       }
       return false;
       */
       //Method 2
       set<int> count;
       for( auto x:nums){
           count.insert(x);
       }
       
       if(count.size()==nums.size())
       {
           return false;
       }
       return true;
    }
};