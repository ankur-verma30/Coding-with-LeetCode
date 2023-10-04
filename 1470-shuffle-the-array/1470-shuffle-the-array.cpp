class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> beg;
        vector<int> end;
        int i=0,j=0;

        for(int i=0;i<nums.size();i++)
        {
            if(i<n)
            beg.push_back(nums[i]);
            else
            end.push_back(nums[i]);
        }

        while(2*i<nums.size()){
            nums[j]=beg[i];
            j++;
            nums[j]=end[i];
            j++;
            i++;
        }
        return nums;
    }
};