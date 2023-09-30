class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
         unordered_map<int, int> count;
    int OneFourthLen = arr.size() / 4;

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
        if (count[arr[i]] > OneFourthLen) {
            return arr[i]; // Found the special integer, no need to continue.
    }
    }
    return -1;  
    }
};