class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,List<Integer>>map=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<n;i++){
            int value=nums[i];
            map.putIfAbsent(value, new ArrayList<>());
            map.get(value).add(i);
        }

        for(Map.Entry<Integer,List<Integer>> entry:map.entrySet()){
            List<Integer> value=entry.getValue();

            for(int i=1;i<value.size();i++){
                if((Math.abs(value.get(i)-value.get(i-1)))<=k) return true;
            }
        }

        return false;
    }
}