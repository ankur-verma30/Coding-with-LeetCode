class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& pass,
                              int capacity) {
        sort(buses.begin(), buses.end());
        sort(pass.begin(), pass.end());

        int cp, ans, i;
        int j = 0;
        int size = pass.size();

        for (i = 0; i < buses.size(); i++) {
            cp = 0;
            while (j < size && cp < capacity && pass[j] <= buses[i]) {
                j++;
                cp++;
            }
        }

        i -= 1;
        j -= 1;

        if (cp < capacity)
            ans = buses[i];
        else
            ans = pass[j];

        while (j >= 0 && ans == pass[j]) {
            ans--;
            j--;
        }

        return ans;
    }
};