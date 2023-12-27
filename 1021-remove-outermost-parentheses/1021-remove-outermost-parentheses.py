class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res=""
        count=0;
        length=len(s)
        for i in range(0,length):
            if s[i]=='(' and count==0:
                count=count+1
            elif s[i]=='(' and count>=1:
                res=res+s[i]
                count=count+1
            elif s[i]==')' and count>1:
                res=res+s[i]
                count=count-1;
            elif s[i]==')' and count==1:
                count=count-1;
            i=i+1
        return res;
        