class Solution {
    public String frequencySort(String s) {

        Map<Character, Integer> map = new HashMap<>();

        for (char ch : s.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        List<Map.Entry<Character, Integer>> list =
                new ArrayList<>(map.entrySet());

        list.sort((a, b) -> {
            if (!a.getValue().equals(b.getValue()))
                return b.getValue() - a.getValue();

            char c1 = a.getKey();
            char c2 = b.getKey();

            if (Character.isUpperCase(c1) && Character.isLowerCase(c2))
                return -1;
            if (Character.isLowerCase(c1) && Character.isUpperCase(c2))
                return 1;

            return c1 - c2;
        });

        StringBuilder sb = new StringBuilder();

        for (Map.Entry<Character, Integer> e : list) {
            for (int i = 0; i < e.getValue(); i++) {
                sb.append(e.getKey());
            }
        }

        return sb.toString();
    }
}
