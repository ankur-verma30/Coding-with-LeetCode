class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=k;
        reverse(num.begin(),num.end());

        for(int i=0;i<num.size();i++){
            int sum=num[i]+carry;
            num[i]=sum%10;
            carry=sum/10;
        }
        while(carry){
            int digit=carry%10;
            num.push_back(digit);
            carry=carry/10;
        }

       reverse(num.begin(),num.end());
       return num;

    }
};