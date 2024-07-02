class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());

    auto itr1 = nums1.begin();
    auto itr2 = nums2.begin();
    while (itr1 != nums1.end() && itr2 != nums2.end()) {
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