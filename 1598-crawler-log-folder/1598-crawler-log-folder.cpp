class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0, n = logs.size();
        for (int i = 0; i < n; i++) {
            if (logs[i] == "./")
                continue;
            else if (logs[i] == "../"){
                count=(count>0) ? count-1 :0;
            }     
            else
                count++;
        }

        return (count > 0) ? count : 0;
    }
};