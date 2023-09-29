class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = 0;
    int count0 = 0;
    string ones = "";
    string zeroes = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            ones = '1'; // Concatenate '1' characters
            count1++;
        }
        else if (s[i] == '0') {
            zeroes = '0'; // Concatenate '0' characters
            count0++;
        }
    }
    
    string result = ones; // Initialize result with the '1' characters


        for(int i=0;i<count0;i++) 
        result =zeroes+result; // Append '0' characters

        for(int i=0;i<count1-1;i++) 
        result =ones+result ; // Append '0's for additional '1's
    
    return result;
    }
};