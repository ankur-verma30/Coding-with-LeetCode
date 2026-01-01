class Solution {
    public int[] plusOne(int[] digits) {
        int n=digits.length, carry=1;
        List <Integer> list=new ArrayList<>();

        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+carry;
            if(sum>=10) {
                sum=sum%10;
                list.add(sum);
                carry=1;
            }
            else {
                list.add(sum);
                carry=0;
            }

        }

        if(carry==1) list.add(1);
        Collections.reverse(list);

          int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i);
        }
        return ans;
    }
}