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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extraEdges = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findUltimateParent(u) == ds.findUltimateParent(v))
                extraEdges++;
            ds.unionBySize(u, v);
        }

        int noOfComponents = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                noOfComponents++;
        }

        int ans = noOfComponents - 1;

        return extraEdges >= ans ?  ans : -1;
    }
};