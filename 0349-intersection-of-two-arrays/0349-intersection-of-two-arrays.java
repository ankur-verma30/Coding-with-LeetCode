class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer>list=new HashSet<>();

        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int n1=nums1.length, n2=nums2.length,i=0,j=0;

        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                list.add(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }

        int size=list.size(),index=0;
        int[] ans=new int[size];
        for(int val:list){
            ans[index++]=val;
        }

        return ans;
    }
}