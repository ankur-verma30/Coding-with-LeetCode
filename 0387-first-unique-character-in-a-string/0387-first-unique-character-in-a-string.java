class Solution {
    public int firstUniqChar(String s) {
        Map<Character,List<Integer>> map=new HashMap<>();

        int n=s.length();

        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            map.putIfAbsent(ch, new ArrayList<>());
            map.get(ch).add(i);
        }

        int ans=Integer.MAX_VALUE;
        for(Map.Entry<Character,List<Integer>> entry: map.entrySet()){
            List<Integer> list=entry.getValue();
            if(list.size()==1) ans=Math.min(ans,list.get(0));
        }

        return (ans==Integer.MAX_VALUE) ? -1 : ans;

    }
}