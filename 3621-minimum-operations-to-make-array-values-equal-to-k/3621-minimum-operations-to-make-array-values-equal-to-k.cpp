class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());

        int operations=0;
        for(auto it:st){
            if(it>k) operations++;
            else if(it<k) return -1;
        } 

        return operations;
    }
};