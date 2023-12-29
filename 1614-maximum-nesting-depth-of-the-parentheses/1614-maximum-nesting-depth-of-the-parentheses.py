class Solution:
    def maxDepth(self, s: str) -> int:
        count=0
        depth=0
        length=len(s)

        for i in range(0,length):
            if s[i]=='(':
                count=count+1
                depth=max(depth,count)
            elif s[i]==')' and count>=1:
                count=count-1    
        
        return depth