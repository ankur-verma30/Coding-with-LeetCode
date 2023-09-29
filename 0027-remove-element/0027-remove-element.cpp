class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     vector<int>::iterator pend;
     vector<int> res;

     pend=remove(nums.begin(),nums.end(),val);
      for (auto p = nums.begin(); p != pend; ++p){
          res.push_back(*p);
      }
      return res.size();

    }
};