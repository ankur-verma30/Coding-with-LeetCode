class Solution {
    public int longestPalindrome(String s) {
        Map<Character,Integer>freq=new HashMap<>();
        int n = s.length(), maxOddLength = 0, totalLength = 0;

        for (int i = 0; i < n; i++) {
            freq.put(s.charAt(i), freq.getOrDefault(s.charAt(i), 0) + 1);
        }

        boolean hasOdd=false;
        for(int value:freq.values()){
            if(value%2!=0){
                totalLength+=value-1;
                hasOdd=true;
            }
            else totalLength+=value;


        }

        return totalLength +((hasOdd) ? 1 : 0) ;
    }
}