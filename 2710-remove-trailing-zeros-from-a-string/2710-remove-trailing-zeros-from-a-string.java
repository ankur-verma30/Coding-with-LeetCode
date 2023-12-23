class Solution {
    public String removeTrailingZeros(String num) {
      int n=num.length();
      int count=num.length();

      if(num.charAt(n-1)!='0')  return num;

      for(int i=n-1;i>=0;i--){
          if(num.charAt(i)=='0')
          count--;
          else 
          break;
      }  
      return num.substring(0,count);
    }
}