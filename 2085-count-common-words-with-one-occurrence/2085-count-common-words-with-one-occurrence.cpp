class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> map1, map2;

        for (string str : words1)
            map1[str]++;

        for (string str : words2)
            map2[str]++;

        int count = 0;
        for (auto it : map1) {
            string str=it.first;
            int freq=it.second;
            if (freq != 1)
                continue;
            if (map2.find(str) != map2.end()) {
                int freq = map2[str];
                if (freq == 1)
                    count++;
            }
        }

        return count;
    }
};