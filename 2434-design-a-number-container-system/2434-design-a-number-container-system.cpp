class NumberContainers {
public:
    unordered_map<int, set<int>> smallestIndex;
    unordered_map<int, int> indexToNumber;

    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            smallestIndex[oldNumber].erase(index);
            if (smallestIndex[oldNumber].empty()) {
                smallestIndex.erase(oldNumber);
            }
        }

        indexToNumber[index] = number;
        smallestIndex[number].insert(index);
    }

    int find(int number) {
        if (smallestIndex.find(number) == smallestIndex.end() ||
            smallestIndex[number].empty()) {
            return -1;
        }
        return *smallestIndex[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */