class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] < target) {
                i++;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                return {i + 1, j + 1}; // Adding 1 to convert to 1-indexed
            }
        }
       
          return {-1, -1}; // Return if no solution is found
    }
};