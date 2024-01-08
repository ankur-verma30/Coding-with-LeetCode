class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>res1;
        vector<int>res2;
        unordered_map<int,int>mp1,mp2;


        for(int i=0;i<nums1.size();i++)
                mp1[nums1[i]]++;

        for(int i=0;i<nums2.size();i++)
        mp2[nums2[i]]++;       
        

       for(int i=0;i<nums1.size();i++){
           if(!(mp2.find(nums1[i])!=mp2.end())){
               res1.push_back(nums1[i]);
               mp2[nums1[i]]=1;
           }
       }

       for(int i=0;i<nums2.size();i++){
           if(!(mp1.find(nums2[i])!=mp1.end())){
               res2.push_back(nums2[i]);
               mp1[nums2[i]]=1;
           }
       }

        return {res1,res2};
    }
};