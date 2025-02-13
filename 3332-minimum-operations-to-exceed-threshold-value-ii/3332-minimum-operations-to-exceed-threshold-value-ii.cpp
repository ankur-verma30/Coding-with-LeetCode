class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         priority_queue< long long , vector<long long >,
          greater<long long >> pq(nums.begin(), nums.end());
        long long count = 0;
        
        while (pq.top() < k) {
            if (pq.size() < 2) break;
            long long n1 = pq.top();
            pq.pop();
            long long n2 = pq.top();
            pq.pop();
            long long val = min(n1,n2)*2LL+max(n1,n2);
            pq.push(val);
            count++;
        }
        
        return count; 
    }
};