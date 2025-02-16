class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end()); 
        int n = pizzas.size();
        int m = n / 4;
        int oddCount = (m + 1) / 2;
        int evenCount = m - oddCount;
        
        long long total = 0;
        int right = n - 1;
        
        for (int i = 0; i < oddCount; i++) {
            total += pizzas[right];
            right--;
            
        }
        for (int i = 0; i < evenCount; i++) {
            int first = pizzas[right];
            right--;
            int second = pizzas[right];
            right--;
            total += second;
           
        }
        return total;
    }
};