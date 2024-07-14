class Solution {
public:
string smallest(string& temp){
        int count=0;
        for(int i=1;i<temp.length();i++){
            if(count==1) break;
            int val1=temp[i-1]-'0';
            int val2=temp[i]-'0';
            if(val1%2==0 && val2%2==0){
                if(val1>val2){
                    swap(temp[i],temp[i-1]);
                    count++;
                }
            }
                else if(val1%2!=0  && val2%2!=0){
                    if(val1>val2){
                    swap(temp[i],temp[i-1]);
                    count++;
                } 
                }
                
            
        }
        return temp;
    }
    string getSmallestString(string s) {

        string res1=smallest(s);
        
        reverse(s.begin(),s.end());
        
        string res2=smallest(s);
        reverse(res2.begin(),res2.end());
        
        return min(res1,res2);
    }
};