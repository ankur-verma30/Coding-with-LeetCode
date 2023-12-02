class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // `pre[i]` is the product of `nums[0] * nums[1] * ... * nums[i - 1]`
        vector<int> pre(n, 1);
        for (int i = 1; i < n; i++) 
        pre[i] = pre[i - 1] * nums[i - 1];

        // `post[i]` is the product of `nums[i + 1] * nums[i + 2] * ... * nums[n - 1]`
        vector<int> post(n, 1);
        for (int i = n - 2; i >= 0; i--) 
        post[i] = post[i + 1] * nums[i + 1];
        
        // `pre[i] * post[i]` is the product of all the elements of `nums` except `nums[i]`
        vector<int> result(n);
        for (int i = 0; i < n; i++) 
        result[i] = pre[i] * post[i];


        return result;
    }
};