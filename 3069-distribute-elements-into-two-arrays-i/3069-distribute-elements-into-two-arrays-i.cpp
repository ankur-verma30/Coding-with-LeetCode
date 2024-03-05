class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        int i=2;
        int len=nums.size();
        
        while(i<len){
            if(arr1[arr1.size()-1]>arr2[arr2.size()-1]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
            i++;
        }
        
      for(auto x:arr2) arr1.push_back(x);
        
        return arr1;
    }
};