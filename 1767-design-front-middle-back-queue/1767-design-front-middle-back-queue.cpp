class FrontMiddleBackQueue {
public:
    deque<int> dq;

    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        dq.push_front(val);
    }

    void pushMiddle(int val) {
        dq.insert(dq.begin() + dq.size() / 2, val);
    }

    void pushBack(int val) {
        dq.push_back(val);
    }

    int popFront() {
        if (dq.empty()) return -1;
        int ans = dq.front();
        dq.pop_front();
        return ans;
    }

    int popMiddle() {
        if (dq.empty()) return -1;
        int midIndex = (dq.size() - 1) / 2;
        int ans = dq[midIndex];
        dq.erase(dq.begin() + midIndex);
        return ans;
    }

    int popBack() {
        if (dq.empty()) return -1;
        int ans = dq.back();
        dq.pop_back();
        return ans;
    }
};