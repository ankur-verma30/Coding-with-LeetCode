class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> smapT = new HashMap<>();
        Map<Character, Character> tmapS = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);

            if (smapT.containsKey(c1)) {
                if (smapT.get(c1) != c2) return false;
            } else  smapT.put(c1, c2);
            

            if (tmapS.containsKey(c2)) {
                if (tmapS.get(c2) != c1) return false;
            } else tmapS.put(c2, c1);
            
        }
        return true;
    }
}
