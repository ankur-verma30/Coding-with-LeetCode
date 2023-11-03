class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        double mean=0;
        int i=0,j=nums.size()-1;
        set<double>a;
    
        sort(nums.begin(),nums.end());

        while(i<j){
             mean=(nums[i]+nums[j])/2.0;
             a.insert(mean);
             i++;
             j--;
             }  
        
        return a.size();
        

    }
};