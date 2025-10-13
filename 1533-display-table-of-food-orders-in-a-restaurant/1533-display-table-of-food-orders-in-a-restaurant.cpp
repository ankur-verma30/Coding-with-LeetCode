class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        set<int> tableNum;
        map<pair<int, string>, int> freq; // key = tableNumber,food value =++;

        for (vector<string> order : orders) {
            string tableNumber = order[1];
            string foodItem = order[2];
            foods.insert(foodItem);
            tableNum.insert(stoi(tableNumber));
            freq[{stoi(tableNumber), foodItem}]++;
        }

        vector<vector<string>> result;

        vector<string> temp = {"Table"};
        for (const string &c : foods)
            temp.push_back(c);

        result.push_back(temp);

        for (const auto table : tableNum) {
            vector<string> curr;
            curr.push_back(to_string(table));
            for (const auto food : foods) {
                int count = freq[{table, food}];
                curr.push_back(to_string(count));
            }
            result.push_back(curr);
        }

        return result;
    }
};