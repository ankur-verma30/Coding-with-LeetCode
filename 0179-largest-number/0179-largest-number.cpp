class Solution {
public:
    bool static compare(const string& a, const string& b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {

        string res;
        vector<string> temp;

        for (int i = 0; i < nums.size(); i++)
            temp.push_back(to_string(nums[i]));

        sort(temp.begin(), temp.end(), compare);
        if (temp[0] == "0")
            return "0";

        for (auto x : temp)
            res += x;

        return res;
    }
};