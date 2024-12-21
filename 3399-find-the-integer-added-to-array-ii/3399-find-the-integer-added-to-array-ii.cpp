class Solution {
public:
    bool checkMinDifference(vector<int>&nums1,vector<int>&nums2,int difference){    
        int count=0;

        for(int i=0,j=0;i<nums1.size() && j<nums2.size();i++){
            if(nums1[i]+difference!=nums2[j]) count++;
            else j++;
        }
        return (count<=2);
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int ans=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            int diff=nums2[0]-nums1[i];
            if(checkMinDifference(nums1,nums2,diff)) ans=min(ans,diff);
        }

        return ans;
    }
};