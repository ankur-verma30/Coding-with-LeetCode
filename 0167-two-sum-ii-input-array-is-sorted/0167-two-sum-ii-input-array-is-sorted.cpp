class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;

        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(numbers.begin(), numbers.end(),
                                  target - numbers[i]);
            if (it != numbers.end()) {
                int position = it - numbers.begin();
                if(position==i) continue;
                if(numbers[i]+numbers[position]!=target) continue;
                ans.push_back(i + 1);
                ans.push_back(position + 1);
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};