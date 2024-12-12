class Solution {
public:
    int halveArray(vector<int>& nums) {
         priority_queue<long double> pq;
        long double sum = 0;
        
        for (const auto& it : nums) {
            sum += it;
            pq.push(it);
        }

        long double target = sum / 2.0;
        long double newSum = sum;
        int operations = 0;

        while (newSum > target) {
            long double element = pq.top();
            pq.pop();
            long double half = element / 2.0;
            newSum -= half;
            pq.push(half);
            operations++;
        }

        return operations;
    
    }
};