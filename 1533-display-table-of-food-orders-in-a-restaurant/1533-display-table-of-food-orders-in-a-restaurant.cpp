class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        set<int> tableNum;
        map<pair<int, string>, int> freq; // key = (tableNumber, foodItem)

        for (vector<string> order : orders) {
            int table = stoi(order[1]);
            string foodItem = order[2];
            foods.insert(foodItem);
            tableNum.insert(table);
            freq[{table, foodItem}]++;
        }

        vector<vector<string>> result;

        // Header row
        vector<string> header = {"Table"};
        for (const string& food : foods)
            header.push_back(food);
        result.push_back(header);

        // Rows for each table
        for (int table : tableNum) {
            vector<string> row;
            row.push_back(to_string(table));
            for (const string& food : foods) {
                int count = freq[{table, food}];
                row.push_back(to_string(count));
            }
            result.push_back(row);
        }

        return result;
    }
};
