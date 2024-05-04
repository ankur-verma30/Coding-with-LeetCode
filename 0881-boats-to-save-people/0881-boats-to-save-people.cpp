class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0, right = people.size() - 1;
        int count = 0;

        while (left <= right) {
            // If the heaviest and lightest people can fit in one boat
            if (people[left] + people[right] <= limit) {
                count++;
                left++;
                right--;
            } else { // If only the heaviest person fits in the boat
                count++;
                right--;
            }
        }
        return count;
    }
};