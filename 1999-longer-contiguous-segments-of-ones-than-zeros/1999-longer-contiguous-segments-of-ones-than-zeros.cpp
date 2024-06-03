class Solution {
public:
    bool checkZeroOnes(string s) {
        int count1=0,count0=0;
        int maxCount1=0,maxCount0=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count0=0;
                count1++;
                maxCount1=max(maxCount1,count1);
            }
            else{
                count1=0;
                count0++;
                maxCount0=max(maxCount0,count0);
            }
        }
        return (maxCount1>maxCount0)?true:false;
    }
};