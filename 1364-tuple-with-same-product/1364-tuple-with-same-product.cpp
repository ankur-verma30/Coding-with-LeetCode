class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<4) return 0;
        unordered_map<int, int> product;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int pro=nums[i]*nums[j];
                product[pro]++;
                }
            }
        
        int ans=0;
        for(const auto &[prod,freq]:product){
                int temp=(freq*(freq-1))/2;
                ans+=(temp*8);
        }

        return ans;
    }
};