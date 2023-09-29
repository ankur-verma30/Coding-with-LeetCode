class Solution {
public:
    int findMin(vector<int>& nums) {

        // Cheap way of doing 
        int  min=*min_element(nums.begin(),nums.end());
        return min;
    }
};