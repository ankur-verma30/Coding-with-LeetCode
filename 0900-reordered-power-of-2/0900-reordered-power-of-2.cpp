class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if ((n & (n - 1)) == 0)
            return true;

        string str = to_string(n);
        sort(str.rbegin(), str.rend());
        map<char, int> mp;
        for (const auto& it : str)
            mp[it]++;

        n = stoi(str);

        int i = 0;
        map<char, int> temp;
        while ((1 << i) <= n) {
            int num = (1 << i);
            string st = to_string(num);
            for (const auto& it : st)
                temp[it]++;
            if (temp == mp)
                return true;
            i++;
            temp.clear();
        }
        return false;
    }
};