class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0,total=0;

        for(int i=0;i<rolls.size();i++) sum+=rolls[i];
        total=(m+n)*mean;

        int rem=total-sum;
        if(rem<n) return {};

        vector<int>arr(n,0);
        int i=0;

        while(rem--){
            arr[i%n]+=1;
            if(arr[i%n]>6) return {};
            i++;
        }

        return arr;
    }
};