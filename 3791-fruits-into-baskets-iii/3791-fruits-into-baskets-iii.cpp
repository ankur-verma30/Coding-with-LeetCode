vector<int> segTree;
class SegmentTree {
public:
    void constructTree(const vector<int>& baskets, int start, int end, int n) {
        if (start == end) {
            segTree[n] = baskets[start];
            return;
        }
        int mid = start + (end - start) / 2;
        constructTree(baskets, start, mid, 2 * n);
        constructTree(baskets, mid + 1, end, 2 * n + 1);
        segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
    }

    bool search(int n, int start, int end, int key) {
        if (segTree[n] < key)
            return false;
        if (start == end) {
            segTree[n] = -1;
            return true;
        }

        int mid = start + (end - start) / 2;
        bool pos = (segTree[2 * n] >= key)
                       ? search(n * 2, start, mid, key)
                       : search(n * 2 + 1, mid + 1, end, key);
        segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
        return pos;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), unplaced = 0;
        segTree.assign(4 * n, 0);
        SegmentTree segment;
        segment.constructTree(baskets, 0, n - 1, 1);

        for (const auto& fruit : fruits) {
            if (!segment.search(1, 0, n - 1, fruit))
                unplaced++;
        }

        return unplaced;
    }
};