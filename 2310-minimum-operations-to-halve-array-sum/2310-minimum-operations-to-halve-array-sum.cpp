class Solution {
public:
    int halveArray(vector<int>& nums) {
         priority_queue< double> pq;
         double sum = 0;
        
        for (const auto& it : nums) {
            sum += it;
            pq.push(it);
        }

        double target = sum / 2.0;
         double newSum = sum;
        int operations = 0;

        while (newSum > target) {
            double element = pq.top();
            pq.pop();
            double half = element / 2.0;
            newSum -= half;
            pq.push(half);
            operations++;
        }

        return operations;
    
    }
};