class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
    int len = nums.size();
        int sum = 0, Totalsum = 0;
        for (int x : nums)
            sum += x;
        for (int i = 0; i < len; i++)
        { int Digitsum=0,rem=0;
            while (nums[i] > 0)
            {
                rem = nums[i] % 10;
                Digitsum += rem;
                nums[i] /= 10;
            }
            Totalsum += Digitsum;
        }
        return abs(Totalsum - sum);
    }
};