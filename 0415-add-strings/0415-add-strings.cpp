class Solution {
public:
    string addStrings(string num1, string num2) {
       

        int l1=num1.length()-1;
        int l2=num2.length()-1;
        int carry = 0;
        string ans;


        while(true){
            if(l1>=0 && l2>=0){
                char ch = addChar(num1[l1],num2[l2],carry);
                ans.push_back(ch);
                l1--;
                l2--;
            }
            else if(l1>=0){
                char ch = addChar(num1[l1],'0',carry);
                ans.push_back(ch);
                l1--;
            }
            else if(l2>=0){
                char ch = addChar('0',num2[l2],carry);
                ans.push_back(ch);
                l2--;
            }
            else if(carry>0){
                ans.push_back(carry+48);
                carry = 0;
            }
            else
                break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    private:
     char addChar(char a , char b , int &carry){
        char ans = carry+a+b-48;
        if(ans>57){
            carry=1;
            ans -= 10;
            return ans;
        }
        else{
            carry=0;
            return ans;
        }
     }

};