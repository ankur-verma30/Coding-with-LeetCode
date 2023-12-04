class Solution {
public:
    string largestGoodInteger(string num) {
        int mx=0,val=0;
        bool flag=false;
        for(int i=1;i<num.length()-1;i++){
            if (num[i - 1] == num[i] && num[i] == num[i + 1]){
             val=(num[i]-'0');
             flag=true;
            }
            mx=max(val,mx);
        }
        string res;
        if(flag){
        char ch=mx+'0';
        return res+ch+ch+ch;
        }

        return res;
            }

};