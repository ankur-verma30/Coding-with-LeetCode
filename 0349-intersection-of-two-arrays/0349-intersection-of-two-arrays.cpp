class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         // Sort both vectors
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        // Initialize two pointers
        int p1 = 0;
        int p2 = 0;
        
        // Create set that stores integers appearing in both vectors
        std::unordered_set<int> intersection;

        // Iterate the pointers from left to right
        while (p1 < nums1.size() && p2 < nums2.size()) {
            // Add a value to the set if values at both pointers equal
            if (nums1[p1] == nums2[p2]) {
                intersection.insert(nums1[p1]);
                p1++;
                p2++;
            }
            // Otherwise, increment the pointer of the smaller integer
            else if (nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }

        // Convert intersection to a vector
        std::vector<int> result(intersection.begin(), intersection.end());

        //Return the result
        return result; 
    }
};