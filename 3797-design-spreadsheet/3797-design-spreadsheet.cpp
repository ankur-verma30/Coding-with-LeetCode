class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) { sheet.assign(rows + 1, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        char col = cell[0];
        int row = stoi(cell.substr(1));
        sheet[row][col - 'A'] = value;
    }

    void resetCell(string cell) {
        char col = cell[0];
        int row = stoi(cell.substr(1));
        sheet[row][col - 'A'] = 0;
    }

    int getValue(string formula) {
        string str1, str2;
        bool isDigit1 = true, isDigit2 = true;
        int index = 0;
        for (int i = 1; i < formula.size(); i++) {
            index = i;
            if (formula[i] == '+')
                break;
            if (!isdigit(formula[i]))
                isDigit1 = false;

            str1 += formula[i];
        }

        for (int i = index + 1; i < formula.size(); i++) {
            str2 += formula[i];
            if (!isdigit(formula[i]))
                isDigit2 = false;
        }
        int val1 = 0, val2 = 0;
        if (!isDigit1) {
            char col = str1[0];
            int row = stoi(str1.substr(1));
            val1 = sheet[row][col - 'A'];
        } else
            val1 = stoi(str1);

        if (!str2.empty()) {
            if (!isDigit2) {
                char col = str2[0];
                int row = stoi(str2.substr(1));
                val2 = sheet[row][col - 'A'];
            } else
                val2 = stoi(str2);
        }

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */