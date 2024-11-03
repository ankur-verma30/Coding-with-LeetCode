class Solution {
public:
    bool isBalanced(string num) {
        int EvenSum=0,oddSum=0;

        for(int i=0;i<num.length();i++){
            char ch=num[i];
            if(i%2==0) oddSum+=(ch-'0');
            else EvenSum+=(ch-'0');
        }

        return EvenSum==oddSum;
    }
};