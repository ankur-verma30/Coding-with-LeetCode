class Solution {
    public String maxSumOfSquares(int num, int sum) {
        long totalValue = num * 9;

        if (totalValue < sum)
            return "";

        long difference = totalValue - sum;

        StringBuilder ans = new StringBuilder("");
        for (int i = 0; i < num; i++)
            ans.append('9');

        int index = num - 1;

        while (difference > 9) {
            ans.setCharAt(index, '0');
            index--;
            difference -= 9;
        }

        Character ch = (char) ((9 - (int) difference) + '0');
        ans.setCharAt(index, ch);

        return ans.toString();

    }

}