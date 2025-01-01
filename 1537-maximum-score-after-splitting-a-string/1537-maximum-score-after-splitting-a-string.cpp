class Solution {
public:
    int maxScore(string s){
        int TotalOnes = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            TotalOnes++;
    }

    int mx = 0, ZeroCount = 0, OneCount = 0;

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '0')
            ZeroCount++;
        else
            OneCount++;
        int Remaining = TotalOnes - OneCount;
        int sum = ZeroCount + Remaining;
        mx = max(sum, mx);
    }
    return mx;
}
};