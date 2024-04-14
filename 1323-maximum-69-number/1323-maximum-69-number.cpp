class Solution {
public:
    int ArrayToInteger(vector<int>&digits){
        int res=0;
        for(int i=0;i<digits.size();i++){
            res=res*10+digits[i];
        }

        return res;
    }
    int maximum69Number (int num) {
        vector<int>digits;

        while(num>0){
            int temp=num%10;
            digits.push_back(temp);
            num=num/10;
        }

        reverse(digits.begin(),digits.end());

        for(int i=0;i<digits.size();i++){
            if(digits[i]==9) continue;
            else if(digits[i]==6){
                digits[i]=9;
                break;
            }
        }

        return ArrayToInteger(digits);
    }
};