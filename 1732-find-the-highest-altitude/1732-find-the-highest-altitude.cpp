class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        vector<int>v;
        for(int i=0;i<gain.size();i++)
    {
        v.push_back(sum);
        sum+=gain[i];
    }
    v.push_back(sum);
      return *max_element(v.begin(),v.end());
  
    }
};