class Solution {
    public int singleNumber(int[] nums) {
        
        int xorAns=0;
        for(int num:nums) xorAns=xorAns^num;
        

        return xorAns;
    }
}