class Solution {
public:
    int pivotInteger(int n) {
int low=1,high=n;
int sum1=low,sum2=high;

    if(n==1)
    return 1;

    if(n==2 || n==4)
    return -1;

    while(low<=high){
        if(sum1==sum2 && low==high)
        return low;
        else if(sum1<sum2){
            low++;
            sum1+=low;
        }
        else if(sum1==sum2 && low!=high ){
            low++;
            sum1+=low;
            high--;
            sum2+=high;
        }
        else
        {
            high--;
            sum2+=high;
        }
    }
    return -1;
        }

};