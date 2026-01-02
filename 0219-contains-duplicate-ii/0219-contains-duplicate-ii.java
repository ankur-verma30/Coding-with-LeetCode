class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer>map=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<n;i++){
            int value=nums[i];
            if(map.containsKey(value)){
                int index=map.get(value);
                if(i-index<=k) return true;
            }
            map.put(value,i);
            
        }


        return false;
    }
}