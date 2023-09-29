class Solution {
public:
    double average(vector<int>& salary) {
        double max=*max_element(salary.begin(),salary.end());
        double min=*min_element(salary.begin(),salary.end());

double sum=0;
        for(auto x:salary){
            sum+=x;
        }
       double new_sum=sum-min-max;
       int total_len=salary.size();


        return new_sum/(total_len-2); 
        //can be done using sorting the vector then taking difference from the sum using accumulate
    }
};