class Solution {
public:
    int compareVersion(string version1, string version2) {
        int maxCount = 0, count = 0;
        for (const auto ch : version1) {
            if (ch == '.')
                count++;
        }

        maxCount = max(maxCount, count);
        count = 0;

        for (const auto ch : version2) {
            if (ch == '.')
                count++;
        }
        maxCount = max(maxCount, count);

        vector<int> v1(maxCount+1, 0);
        vector<int> v2(maxCount+1, 0);

        string str = "";
        int index = 0,num=0;
        for (int i = 0; i < version1.length(); i++) {
            str += version1[i];
            if (version1[i] == '.') {
                num = stoi(str);
                v1[index++] = num;
                str = "";
            }
        }
        num = stoi(str);
        v1[index] = num;
        str = "";

        int index2 = 0;

        for (int i = 0; i < version2.length(); i++) {
            str += version2[i];
            if (version2[i] == '.') {
                num = stoi(str);
                v2[index2++] = num;
                str = "";
            }
        }
        num = stoi(str);
        v2[index2] = num;
        str = "";

        for (int i = 0; i < maxCount+1; i++) {
            if (v1[i] > v2[i])
                return 1;
            if (v1[i] < v2[i])
                return -1;
        }

        return 0;
    }
};