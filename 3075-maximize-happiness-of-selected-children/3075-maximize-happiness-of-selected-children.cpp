class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long totalHappiness = 0;
        int n = nums.size();

        priority_queue<int> pq;
        bool isSelected = false;

        for (const auto it : nums)
            pq.push(it);

        long long count = 0;
         while (k-- > 0) {
            if (!isSelected) {
                totalHappiness += pq.top();
                pq.pop();
                isSelected = true;
            } else {
                count++;
                long long value = (pq.top() - count > 0) ? pq.top() - count : 0;
                totalHappiness += value;
                pq.pop();
            }
        }

        return totalHappiness;
    }
};

// 83+61+1=