class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";
        int len = num.length();

        for (int i = 0; i <= len - 3; i++) {
            if (num.charAt(i) == num.charAt(i + 1) &&
                    num.charAt(i + 1) == num.charAt(i + 2)) {
                char ch = num.charAt(i);
                String str = "" + ch + ch + ch;
                if (str.compareTo(ans) > 0)
                    ans = str;

            }
        }
        return ans;
    }
}