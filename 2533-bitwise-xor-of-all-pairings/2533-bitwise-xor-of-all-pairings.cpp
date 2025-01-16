class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 % 2 == 0 && n2 % 2 == 0)
            return 0;

        if (n1 % 2 != 0 && n2 % 2 != 0) {
            int xor1 = 0, xor2 = 0;

            for (const auto& it : nums1)
                xor1 ^= it;
            for (const auto& it : nums2)
                xor2 ^= it;

            return xor1 ^ xor2;
        }

        if (n1 % 2 == 0 && n2 % 2 != 0) {
            int xor1 = 0;
            for (const auto& it : nums1) xor1 ^= it;
            return xor1;
        } else if (n1 % 2 != 0 && n2 % 2 == 0) {
            int xor2 = 0;
             for (const auto& it : nums2) xor2 ^= it;
            return xor2;
        }

        return 0;
    }
};