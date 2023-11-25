class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = 0;
    // Xor of all the numbers in the vector
    for (int i = 0; i < nums.size(); i++)
        xor1 ^= nums[i];

    // find the position of the first set bit in the xor
    int pos = 0;
    int temp = xor1;
    while ((temp & 1) == 0)
    {
        pos++;
        temp = temp >> 1;
    }
    // fitler the number of array which have set bit at the position index

    int setA = 0;
    int setB = 0;
    int mask = (1 << pos);
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & mask) > 0)
            setA ^= nums[i];
        else
            setB ^= nums[i];
    }

    return {setA, setB};
    }
};