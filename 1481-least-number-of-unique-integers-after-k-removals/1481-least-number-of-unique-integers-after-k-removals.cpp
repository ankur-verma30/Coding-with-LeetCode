class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        if (arr.size() == k)
            return 0;

        unordered_map<int, int> mp;

        // Adding elements in the map
        for (auto x : arr)
            mp[x]++;

        vector<int> freq;
        int count = 0;
        for (auto x : mp)
            freq.push_back(x.second);

        sort(freq.begin(), freq.end());

        int i=0;
       for(;i<freq.size();i++){
            k-= freq[i];               
            if(k<=0) break; 
       }   
        if(k==0) return(freq.size()-i-1); 
        
        return(freq.size()-i);
    }
};