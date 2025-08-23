class Solution {
    public int majorityElement(int[] nums) {
       int count=0,element=0,n=nums.length;

        for(int num:nums){
            if(count==0){
                element=num;
                count=1;
            }
            else if(count>0 && element==num) count++;
            else count--;
        }

        int freq=0;
        for(int num:nums){
            if(element==num) freq++;
        }

        return (freq>(n/2)) ? element : 0;
    }
}