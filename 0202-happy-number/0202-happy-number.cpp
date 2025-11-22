class Solution {
public:
    int sumOfDigitSquares(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=(rem*rem);
            n/=10;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>visited;
        while(n>1){
            int newNum=sumOfDigitSquares(n);
            if(visited.count(newNum)) return false;
            visited.insert(newNum);
            n=newNum;
        }

        return true;
    }
};