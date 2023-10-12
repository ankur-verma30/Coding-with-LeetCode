class Solution {
public:
    string defangIPaddr(string address) {
        string str="";
        int len=address.length();
        for(int i=0;i<len;i++){
            if(address[i]!='.')
                str+=address[i];
            else{
                str+='[';
                str+='.';
                str+=']';
            }
            
        }
        return str;
    }
};