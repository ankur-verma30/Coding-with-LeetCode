class Solution {
public:
    string addBinary(string str1, string str2) {
       string result = "";
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if (str1.length() > str2.length())
        swap(str1, str2);
        
    int carry = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        int d1 = CharToNumber(str1[i]);
        int d2 = CharToNumber(str2[i]);
        int sum = d1 + d2 + carry;
        int output_digit = sum % 2;
        result.push_back(IntToChar(output_digit));
        carry = sum / 2;
    }
    for (int i = str1.length(); i < str2.length(); i++)
    {
        int d2 = CharToNumber(str2[i]);
        int sum = d2 + carry;
        int output_digit = sum % 2;
        result.push_back(IntToChar(output_digit));
        carry = sum / 2;
    }

    if (carry)
        result.push_back('1');

    reverse(result.begin(), result.end());

    return result;

    }
    private:
    int CharToNumber(char ch){
        return ch-'0';
    }
    char IntToChar(int digit){
        return digit+'0';
    }
};