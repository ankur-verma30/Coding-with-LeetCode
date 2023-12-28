class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
         st=s+s
         stlen=len(st)
         value=False
         length=len(goal)

         for i in range(0,stlen):
             str=st[i:i+length]
             if str==goal and len(str)==(len(st))/2:
                 value=True
                 break
             else:
                 value=False    
    
         return value
          