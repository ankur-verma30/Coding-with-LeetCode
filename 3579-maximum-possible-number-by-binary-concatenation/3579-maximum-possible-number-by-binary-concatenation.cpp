class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int maxVal = 0;
        sort(nums.begin(), nums.end());
        do {
            string concat = "";
            for (int num : nums)
                concat += bitset<8>(num).to_string().substr(
                    bitset<8>(num).to_string().find('1'));
            int decimal = stoi(concat, nullptr, 2);
            maxVal = max(maxVal, decimal);
        } while (next_permutation(nums.begin(), nums.end()));

        return maxVal;
    }
};