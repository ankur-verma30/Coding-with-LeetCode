class Solution {
    public int maxDepth(String s) {
        int count=0,Depth=0;

     for(int i=0;i<s.length();i++){
         if(s.charAt(i)=='(' ){
             count++;
             Depth=Integer.max(count,Depth);
         }
         else if(s.charAt(i)==')' && count>=1)
         count--;
     }   
     return Depth;
    }
}