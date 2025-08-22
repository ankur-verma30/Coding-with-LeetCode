class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>hs=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            if(hs.containsKey(target-nums[i])){
                int index=hs.get(target-nums[i]);
                if(index!=i) return new int[]{index,i};
            }
            hs.put(nums[i],i);
        }

        return new int[]{-1,-1};
    }
}