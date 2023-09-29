class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      
    int count=0;
        (str1+str2==str2+str1)? 
        count=gcd(str1.length(),str2.length())
        :count=0;  //condition for gcd
         //can direcly find gdc
    
        return  str1.substr(0,count);;
    }
};