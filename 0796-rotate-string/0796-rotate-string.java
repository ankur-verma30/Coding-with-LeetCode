class Solution {
    public boolean rotateString(String s, String goal) {

        String str=s+s;
    return (str.contains(goal) && goal.length()==(int)str.length()/2)?true:false;
    
       
    }
    
}