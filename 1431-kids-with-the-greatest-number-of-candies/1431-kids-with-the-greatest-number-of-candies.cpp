class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        auto maxi=*max_element(candies.begin(),candies.end());
       for( auto x:candies)
       if(x+extraCandies>=maxi)
       result.push_back(true);
       else
       result.push_back(false);

       return result;
    }
};