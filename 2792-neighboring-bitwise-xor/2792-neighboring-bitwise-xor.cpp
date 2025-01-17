class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n==1 && derived[0]==1) return false;
        int lastValue = derived[n - 1];

        for (int start = 0; start <= 1; ++start) {
            vector<int> orig(n);
            orig[0] = start;
            orig[n - 1] = lastValue ^ orig[0];

            for (int i = 0; i < n - 1; ++i) {
                orig[i + 1] = derived[i] ^ orig[i];
            }
            return (orig[n - 1] == lastValue);
        }

        return false;
    }
};