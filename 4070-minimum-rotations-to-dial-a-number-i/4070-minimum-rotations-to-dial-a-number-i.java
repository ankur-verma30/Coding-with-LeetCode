class Solution {
    public int minRotations(String s) {
        char prev = '0';
        int len = s.length(), ans = 0;

        for (int i = 0; i < len; i++) {
            int distance1 = Math.abs(prev - s.charAt(i));
            int distance2 = Math.abs(9-distance1+1);

            ans += Math.min(distance1, distance2);
            prev=s.charAt(i);
        }

        return ans;
    }
}