class Solution {
    public int firstUniqChar(String s) {
        Map<Character,List<Integer>> map=new HashMap<>();

        int n=s.length();

        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            map.putIfAbsent(ch, new ArrayList<>());
            map.get(ch).add(i);
        }

        for(int i=0;i<n;i++){
            List<Integer> list=map.get(s.charAt(i));
            if(list.size()==1) return list.get(0);
        }

        return -1;

    }
}