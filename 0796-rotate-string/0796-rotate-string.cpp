class Solution {
public:
    bool rotateString(string s, string goal) {
        s=s+s;
        int len=goal.length();

        bool value=false;

        for(int i=0;i<s.length();i++){
           string str=s.substr(i,len);
           if(str==goal && ((int)str.length()==((int)s.length()/2))) {     
                value=true;
                break; 
        }
        else 
        value=false;
        }
        return value;
    }
};