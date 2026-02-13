class Solution {
    public int majorityElement(int[] nums) {
        int element=-1,count=0;

        for(int num:nums){
            if(count==0) element=num;
           if(element==num) count++;
           else count--;
        }

        int totalFreq=0;
        for(int num:nums){
            if(num==element) totalFreq++;
        }

        return totalFreq>nums.length/2 ? element : -1;
    }
}