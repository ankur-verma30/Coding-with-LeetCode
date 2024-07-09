class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int num=cust.size();
        double currTime=cust[0][0];
        double diff=0;

        for(int i=0;i<num;i++){
            
            if(currTime<cust[i][0]) {
                diff+=cust[i][1];
                currTime=cust[i][0]+cust[i][1];

            }
            else{
                currTime+=cust[i][1];
                diff+=(currTime-cust[i][0]);
            }
            
        }

        return diff/(double)num;
    }
};