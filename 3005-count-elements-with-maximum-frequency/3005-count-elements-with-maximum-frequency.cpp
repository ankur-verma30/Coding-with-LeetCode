class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         
        unordered_map<int, int> count;

        for (auto& num : nums) count[num]++;

       
        int maxFreq = 0;
        for (auto x: count) maxFreq = max(maxFreq, x.second);
        
       
        int result = 0;
        for (auto x : count) {
            if (x.second == maxFreq) result += x.second;
        }
        return result;
    }
};