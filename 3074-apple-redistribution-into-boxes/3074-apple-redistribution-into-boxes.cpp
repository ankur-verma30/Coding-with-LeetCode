class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0, size = capacity.size(), i = 0, total = 0;

        for (const auto it : apple)
            sum += it;

        sort(capacity.rbegin(), capacity.rend());
        
        for (int i = 0; i < size; i++) {
            total += capacity[i];
            if (total >= sum)
                return i + 1;
        }

        return size;
    }
};