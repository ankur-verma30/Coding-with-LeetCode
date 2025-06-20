class Solution {
public:
    int MinTimes(int d1, int d2, int ops) { return abs(d1 - d2) + ops * 2; }
    int maxDistance(string s, int k) {
        int Wdis = 0, Edis = 0, Ndis = 0, Sdis = 0, maxAns = 0;

        for (const auto& it : s) {
            if (it == 'N')
                Ndis++;
            else if (it == 'S')
                Sdis++;
            else if (it == 'E')
                Edis++;
            else
                Wdis++;
            int times1 = min({Ndis, Sdis, k});
            int times2 = min({Edis, Wdis, k - times1});
            maxAns = max(maxAns, MinTimes(Ndis, Sdis, times1) +
                                     MinTimes(Edis, Wdis, times2));
        }
        return maxAns;
    }
};