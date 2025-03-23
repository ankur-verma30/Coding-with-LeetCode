class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
       
        int totalWeight=0,count=0;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(flag) break;
            for(int j=1;j<=n;j++){
                totalWeight+=w;
                if(totalWeight>maxWeight){
                    flag=true;
                    break;
                }
                else count++;
            }
        }

        return count;
    }
};