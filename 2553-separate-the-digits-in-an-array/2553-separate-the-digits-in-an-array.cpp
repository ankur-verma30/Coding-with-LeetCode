class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<10)
            result.push_back(nums[i]);
            else{
                int k=result.size();
            Isdigit(nums[i],result);
            reverse(result.begin()+k,result.end());
            }
        }
        return result;

    }

    private:

    void Isdigit(int n, vector<int>&result){
        
        while(n>0){
            int rem=n%10;
          result.push_back(rem);
          n=n/10;
        }
    }
};