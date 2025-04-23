class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        vector<int>freq(n+1,0);

        for(int i=1;i<=n;i++){
            int sum=sumOfDigits(i);
            freq[sum]++;
        }


        auto maxi= *max_element(freq.begin(),freq.end());
        int count=0;

        for(const auto it:freq) {
            if(it==maxi) count++;
        }

        return count;
    }
};