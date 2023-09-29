class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> result;
        for(auto &num : arr)
         result.insert(num);//store the elements in the set to avoid repetition and in the sorted order
        unordered_map<int, int> mp;
        int i = 1;
        for(auto it = result.begin(); it != result.end() ; it++){ 
            mp[*it] = i++;//map each element
        }
        for(auto &num : arr)
         num = mp[num];//this modifies the original array with the index
        return arr;
    }
};