class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
         int rem=purchaseAmount%10;
        if(purchaseAmount%10==0)//basic case
        return 100-purchaseAmount;

        else if(rem<=4){//for numbers having unit place less than 5
           return 100-purchaseAmount+rem;
        }
        else 
        {
            purchaseAmount+=(10-rem);//cases with unit places greater or equal to 5
            return 100-purchaseAmount;
        }
    }
};