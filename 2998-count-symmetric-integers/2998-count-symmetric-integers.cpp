class Solution {
public:
    bool isEqual(string str){
        int n=str.length();
        if(n%2) return false;

        int sum1=0,sum2=0;

        for(int i=0;i<n/2;i++) sum1+=str[i]-'0';
        for(int i=n/2;i<n;i++) sum2+=str[i]-'0';

        return sum1==sum2;
        
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;

        for(int i=low;i<=high;i++){
            string str=to_string(i);
            if(isEqual(str)) count++;
        }

        return count;
    }
};