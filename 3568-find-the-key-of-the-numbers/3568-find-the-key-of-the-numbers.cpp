class Solution {
public:
    vector<int> KeyGeneration(int n, vector<int>& v) {
        int i = 3;
        while (n > 0) {
            int rem = n % 10;
            v[i] = rem;
            n = n / 10;
            i--;
        }

        return v;
    }
    int generateKey(int num1, int num2, int num3) {
        vector<int> v1(4, 0);
        vector<int> v2(4, 0);
        vector<int> v3(4, 0);

        KeyGeneration(num1, v1);
        KeyGeneration(num2, v2);
        KeyGeneration(num3, v3);

        vector<int> res;
        for (int i = 0; i < 4; i++) {
            int temp = min(v1[i], min(v2[i], v3[i]));
            res.push_back(temp);
        }
        int num = 0;
        for (int i = 0; i < res.size(); i++)
            num = num * 10 + res[i];

        return num;
    }
};