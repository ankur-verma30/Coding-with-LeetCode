class Solution {
public:
    string largestOddNumber(string& num) {

        
        for(int i=num.length()-1;i>=0;i--){
            if(num[i]=='7' || num[i]=='9' || num[i]=='3'|| num[i]=='1'|| num[i]=='5')
            return num;
            else
            num.pop_back();
        }

        return num;
        
       
    }
};