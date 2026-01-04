class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0, n = nums.size();

        // unordered_map<int, int> haveFourDivisors;

        for (int i = 0; i < n; i++) {
            // if (haveFourDivisors.count(nums[i])) {
            //     totalSum += haveFourDivisors[nums[i]];
            //     continue;
            // }
            int count = 0, sum = 0, value = nums[i];
            for (int j = 1; j * j <= value; j++) {
                if (value % j == 0) {
                    int quotient = value / j;
                    if (quotient != j) {
                        count += 2;
                        sum += j + quotient;
                    } else {
                        count++;
                        sum += j;
                    }
                }
            }
            if (count == 4) {
                // haveFourDivisors[value] = sum;
                totalSum += sum;
            }
        }

        return totalSum;
    }
};