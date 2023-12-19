class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>result(num_people,0);

        int i=0,count=1;

        while(candies!=0){
            if(i==result.size()) i=0;
            if(count<=candies){
                result[i]+=count;
                candies=candies-count;
                count++;
            }
            else if(count>candies && candies!=0){
            result[i]+=candies;
            candies=0;
            }
            i++;
        }
        return result;
    }
};