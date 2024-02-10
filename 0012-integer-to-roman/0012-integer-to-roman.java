class Solution {
    public String intToRoman(int num) {
         TreeMap<Integer, String> intToRoman = new TreeMap<>(){{
        put(1, "I");
        put(4, "IV");
        put(5, "V");
        put(9, "IX");
        put(10, "X");
        put(40, "XL");
        put(50, "L");
        put(90, "XC");
        put(100, "C");
        put(400, "CD");
        put(500, "D");
        put(900, "CM");
        put(1000, "M");
        }};

        StringBuilder res = new StringBuilder();
        int prev = 1000;

        while (num > 0) {
            if (intToRoman.containsKey(num)) {
                res.append(intToRoman.get(num));
                break;
            }
            for (int key : intToRoman.keySet()) {
                if (key < num)
                    prev = key;
            }
            res.append(intToRoman.get(prev));
            num -= prev;
        }

        return res.toString();
    }

};