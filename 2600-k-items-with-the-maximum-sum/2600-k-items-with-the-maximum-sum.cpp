class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
       int greater=0;
       
        if(k<=numOnes)
        return k;

       if(k>numOnes && k<=(numOnes+numZeros) )
        return numOnes;

        if(k==(numOnes+numZeros))
        return numOnes;


        if((k>(numOnes+numZeros))&&(k<(numOnes+numZeros+numNegOnes))){
             greater=k-(numOnes+numZeros);
         return numOnes-greater;
        }

        if(k==(numOnes+numZeros+numNegOnes))
        return numOnes-numNegOnes;

        if(k>(numOnes+numZeros+numNegOnes)){
         greater=k-(numOnes+numZeros);
         return numOnes-greater;
        }

        return 0;
    }
};