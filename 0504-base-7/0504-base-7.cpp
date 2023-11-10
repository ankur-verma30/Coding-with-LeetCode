class Solution {
public:
    string convertToBase7(int num) {
        int rem=0;
        string str="";

        if(num==0)   //for edge case of 0
        return "0";

        int n=abs(num);
        while(n!=0){
            rem=n%7;
            n=n/7;
            str+=to_string(rem);   //find the string value 
        }

        if(num<0)
        str+='-';   //for -ve add minus(-) sign

        reverse(str.begin(),str.end());  //now reverse the string 

        return str;
    }
};