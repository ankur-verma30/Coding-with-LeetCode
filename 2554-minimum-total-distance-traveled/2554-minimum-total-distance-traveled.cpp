class Solution {
public:
    #define MAX 100000000000000L;
    long long minCost(vector<int>& robot, int robo_pos, vector<int>& factories,
                      int fact_pos, vector<vector<long long>>& memo) {
        if (robo_pos < 0)
            return 0;
        if (fact_pos < 0)
            return MAX;

        if (memo[robo_pos][fact_pos] != -1)
            return memo[robo_pos][fact_pos];

        long long include =
            abs(robot[robo_pos] - factories[fact_pos]) +
            minCost(robot, robo_pos - 1, factories, fact_pos - 1, memo);

        long long exclude =
            minCost(robot, robo_pos, factories, fact_pos - 1, memo);

        return memo[robo_pos][fact_pos] = min(include, exclude);
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        // sort both the array
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factories;

        for (int i = 0; i < factory.size(); i++) {
            int pos = factory[i][0];
            int count = factory[i][1];

            for (int j = 0; j < count; j++)
                factories.push_back(pos);
        }

        int n = robot.size();
        int m = factories.size();

        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        return minCost(robot, n-1, factories, m-1, memo);
    }
};