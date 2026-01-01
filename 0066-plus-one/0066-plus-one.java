class Solution {
    public int[] plusOne(int[] digits) {
        int n=digits.length, carry=1;

        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+carry;
            if(sum>=10) {
                sum=sum%10;
                digits[i]=sum;
                carry=1;
            }
            else {
                digits[i]=(sum);
                carry=0;
            }

        }

        if(carry==0) return digits;
          int[] ans = new int[n+1];
          ans[0]=1;
        for (int i = 1; i <n+1; i++) {
            ans[i] = digits[i-1];
        }
        return ans;
    }
}