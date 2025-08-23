class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer>hs=new HashMap<>();

        int maxi=0,ans=0;
        for(int num:nums){
            hs.put(num,hs.getOrDefault(num,0)+1);
            int freq=hs.get(num);
            if(freq>maxi){
                maxi=freq;
                ans=num;
            }
        }

        return ans;
    }
}