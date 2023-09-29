class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int new_num=0;
        unordered_set<int> s;//in this insertion is faster than ordered set

        for(auto &x:nums){
        s.insert(x);
            new_num=0;

            while(x!=0){
             new_num=new_num*10+(x%10);
             x/=10;
            }
            s.insert(new_num);
        }
        return s.size();


    }
};