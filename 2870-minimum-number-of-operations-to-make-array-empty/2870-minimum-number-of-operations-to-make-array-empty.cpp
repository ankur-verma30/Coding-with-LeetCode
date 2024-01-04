class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>count;
       int operations=0; 

       for(int i=0;i<nums.size();i++)
       count[nums[i]]++;

       for(auto x:count){
            int t = x.second;
            if(t==1)    return -1;
            operations += t/3;
            if(t%3)  operations++;
        }
        
       return operations;
    }
};