class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        int count=1, n = chars.size(), index = 1;

        for (int i = 1; i < n; i++) {
            if (chars[i] == prev) {
                count++;
                continue;
            } else {
                if (count != 1) {
                    string str = to_string(count);
                    for (const auto it : str)
                        chars[index++] = it;
                }
                count=0;
                prev = chars[i];
                chars[index++]=prev;
                count=1;
            }
        }
        if (count != 1) {
        string str = to_string(count);
        for (const auto it : str)
        chars[index++] = it;
                }

        return index;
    }
};