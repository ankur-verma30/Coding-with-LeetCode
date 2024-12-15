class Solution {
public:
    void BellmanRelaxation(unordered_map<string, double>& max_currency,
                           vector<vector<string>>& pairs,
                           vector<double>& rate) {
        int relaxationTime = pairs.size();
        for (int relax = 0; relax < relaxationTime; relax++) {
            for (int i = 0; i < relaxationTime; i++) {
                max_currency[pairs[i][1]] =
                    max(max_currency[pairs[i][1]],
                        max_currency[pairs[i][0]] * rate[i]);
                max_currency[pairs[i][0]] =
                    max(max_currency[pairs[i][0]],
                        max_currency[pairs[i][1]] * (1 / rate[i]));
            }
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1,
                     vector<double>& rates1, vector<vector<string>>& pairs2,
                     vector<double>& rates2) {
        unordered_map<string, double> max_currency;
        max_currency[initialCurrency] = 1;

        BellmanRelaxation(max_currency, pairs1, rates1);
        BellmanRelaxation(max_currency, pairs2, rates2);

        return max_currency[initialCurrency];
    }
};