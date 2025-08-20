class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hst=new HashSet<>();

        for(int num:nums) hst.add(num);

        return hst.size()!=nums.length;
    }
}