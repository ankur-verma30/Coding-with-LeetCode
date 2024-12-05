class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n) {
        size.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ul_p_u = findUltimateParent(u);
        int ul_p_v = findUltimateParent(v);

        if (ul_p_u == ul_p_v)
            return;
        if (size[ul_p_u] < size[ul_p_v]) {
            parent[ul_p_u] = ul_p_v;
            size[ul_p_v] += size[ul_p_u];
        } else {
            parent[ul_p_v] = ul_p_u;
            size[ul_p_u] += size[ul_p_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mpp;
        int total = accounts.size();
        DisJointSet ds(total);

        for (int i = 0; i < total; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mpp.find(accounts[i][j]) == mpp.end())
                    mpp[accounts[i][j]] = i;
                else {
                    int previousIndex = mpp[accounts[i][j]];
                    ds.unionBySize(previousIndex, i);
                }
            }
        }

        unordered_map<int, vector<string>> mergedAccounts;
        for (const auto& [email, index] : mpp) {
            int parentIndex = ds.findUltimateParent(index);
            mergedAccounts[parentIndex].push_back(email);
        }

        vector<vector<string>> result;
        for (const auto& [index, emails] : mergedAccounts) {
            vector<string> temp = emails;
            sort(temp.begin(), temp.end());
            temp.insert(temp.begin(), accounts[index][0]);
            result.push_back(temp);
        }

        return result;
    }
};