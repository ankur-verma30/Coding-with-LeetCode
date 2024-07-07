class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        if (n == 3) {
            if ((colors[0] != colors[1]) && (colors[1] != colors[2]))
                return 1;
        }

        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            if ((colors[i] != colors[i + 1]) &&
                (colors[i + 1] != colors[i + 2]))
                count++;
        }

        if (colors[n - 2] != colors[n - 1] && colors[n - 1] != colors[0])
            count++;
        if (colors[n - 1] != colors[0] && colors[0] != colors[1])
            count++;

        return count;
    }
};