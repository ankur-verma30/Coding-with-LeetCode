class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int yCount=count(customers.begin(),customers.end(),'Y');

        if(yCount==0) return 0;
        int nCount=n-yCount;

        int miniIndex=n+1,minPenalty=INT_MAX,penalty=0;

        //0 -y-0,n-0 
        // 1= y-1

        int currYCount=0,currNCount=0;
        for(int i=0;i<n;i++){
            penalty=yCount-currYCount+currNCount;
            if(penalty<minPenalty){
                minPenalty=penalty;
                miniIndex=i;
            }
            (customers[i]=='Y') ? currYCount++ : currNCount++;
        }
         penalty=yCount-currYCount+currNCount;
        if(penalty<minPenalty){
                minPenalty=penalty;
                miniIndex=n;
            }

        return miniIndex;
    }
};