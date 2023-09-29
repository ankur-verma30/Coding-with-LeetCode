class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> Set;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
            Set.insert(nums[i]);
        
        for(auto x : Set)
            result.push_back(x);

        int len=result.size();
        
        if(len==1)
            return result[0];
  
        if(len==2){
            sort(result.begin(),result.end());
            return result[1];
        }

        if(len>=3)
            return result[len-3];
        
        return result[len];
    }
};