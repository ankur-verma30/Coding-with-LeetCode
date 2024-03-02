
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue< long long int, vector<long long int>, greater<long long int>> pq(nums.begin(), nums.end());
        long long int count = 0;
        
        while (pq.top() < k) {
            if (pq.size() < 2) break;
            long long int n1 = pq.top();
            pq.pop();
            long long int n2 = pq.top();
            pq.pop();
            long long int val = min(n1,n2)*2LL+max(n1,n2);
            pq.push(val);
            count++;
        }
        
        return count;
    }
};
