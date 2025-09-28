class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int divisor=1e9;

        vector<int>ans;

        while(n>9){
            if(n<divisor) divisor=divisor/10;
            else{
                int quotient=n/divisor;
                n=n%divisor;
                ans.push_back(quotient*divisor);
            }
        }

        if(n!=0) ans.push_back(n);
        return ans;
    }
};