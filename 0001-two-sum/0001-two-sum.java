class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>map=new HashMap<>();
        int n=nums.length;
        
        for(int i=0;i<n;i++){
            if(map.containsKey(target-nums[i])){
                int index=map.get(target-nums[i]);
                return new int[]{index,i};
            }
            map.put(nums[i],i);
        }

        return new int[]{-1,-1};
    }
}