class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int, int> elementToIndex;

        for (int i = 0; i < elements.size(); i++) {
            if (elementToIndex.find(elements[i]) == elementToIndex.end())
                elementToIndex[elements[i]] = i;
        }

        vector<int> ans;

        for (const auto group : groups) {
            int minIndex = INT_MAX;

            for (auto divisor = 1; divisor * divisor <= group; divisor++) {
                if (group % divisor == 0) {
                    int otherDivisor = group / divisor;
                    if (elementToIndex.find(divisor) != elementToIndex.end())
                        minIndex = min(minIndex, elementToIndex[divisor]);
                    if (elementToIndex.find(otherDivisor) !=
                        elementToIndex.end())
                        minIndex = min(minIndex, elementToIndex[otherDivisor]);
                }
            }
            cout<<minIndex<<endl;
            ans.push_back(minIndex == INT_MAX ? -1 : minIndex);
        }

        return ans;
    }
};