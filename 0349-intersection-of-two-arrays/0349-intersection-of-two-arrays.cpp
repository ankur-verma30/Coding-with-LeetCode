class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       vector<int> result;

    set<int> set1;
    for(auto x:nums1)
    set1.insert(x);
    set<int> set2;
     for(auto x:nums2)
    set2.insert(x);

    
    auto itr1 = set1.begin();
    auto itr2 = set2.begin();

    while (itr1 != set1.end() && itr2 != set2.end()) {
        if (*itr1 == *itr2) {
            result.push_back(*itr1);
            itr1++;
            itr2++;
        }
         else if (*itr1 < *itr2) 
            itr1++;
             else 
            itr2++;
    }

    return result;
}
};