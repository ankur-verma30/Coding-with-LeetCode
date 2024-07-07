class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        int n=e.size();

        sort(e.begin(),e.end());
        if(e[0]>c) return 0;

        long long sum=0;
        sum+=c;
        for(int i=1;i<n;i++){
            sum+=e[i];
        }

        return sum/e[0];

        
    }
};