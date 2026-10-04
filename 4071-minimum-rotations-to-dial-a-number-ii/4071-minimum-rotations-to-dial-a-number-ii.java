class Solution {
    private int minDistance(char start, char end) { 
            int distance1 = Math.abs(start - end);
            int distance2 = Math.abs(9 - distance1 + 1);

            return Math.min(distance1, distance2);
    }

    private int rotationSum(String s) {
        char prev = '0';
        int len = s.length(), ans = 0;

        for (int i = 0; i < len; i++) {
            int distance1 = Math.abs(prev - s.charAt(i));
            int distance2 = Math.abs(9 - distance1 + 1);

            ans += Math.min(distance1, distance2);
            prev = s.charAt(i);
        }

        return ans;
}

    public int minRotations(int n, String s) {
        int ans=0;

        int count=rotationSum(s);
        
        String reversed = new StringBuilder(s).reverse().toString();

          int count2=rotationSum(reversed);
          int minAns=count;

        for(int i=0;i<n-1;i++){
            int temp=count;
            int value1=minDistance(s.charAt(i),s.charAt(i+1));
            int value2=minDistance(s.charAt(i),s.charAt(n-1));
            temp+=value2-value1;

            minAns=Math.min(minAns,temp);
        }

        return Math.min(minAns,count2);
        
    }
}