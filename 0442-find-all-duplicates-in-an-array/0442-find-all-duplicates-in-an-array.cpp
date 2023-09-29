class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> count;
      
       for(auto e:nums)
       count[e]++;

          vector<int> result;

        for(auto x:count)
        {
            if(x.second>=2)
            result.push_back(x.first);
        }
        return result;


//Method 2
    //    vector<int>ans;

    //   sort(nums.begin(),nums.end());

    //   for(int i=1;i<nums.size();i++){
    //       if(nums[i-1]==nums[i]){
    //           ans.push_back(nums[i]);
    //       }
    //   }
    //   return ans;  
    }
};