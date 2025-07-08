class Solution {
public:
    bool isValidCode(string code){
         if (code.empty()) return false; 
    for (char ch : code) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_set<string> st = {"electronics", "pharmacy", "grocery",
                                    "restaurant"};
        vector<pair<string, string>> newCode;
        vector<string> ans;

        int numberOfCoupons = code.size();

        for (int i = 0; i < numberOfCoupons; i++) {
            if (isActive[i]) {
                if (st.count(businessLine[i]) && isValidCode(code[i])) {
                    newCode.emplace_back(businessLine[i], code[i]);
                }
            }
        }

        sort(newCode.begin(), newCode.end(),
             [](pair<string, string> a, pair<string, string> b) {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        for (const auto it : newCode)
            ans.emplace_back(it.second);

        return ans;
    }
};