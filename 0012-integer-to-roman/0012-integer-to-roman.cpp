class Solution {
public:
    string intToRoman(int num) {
        map<int, string> intToRoman{
            {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
            {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
            {500, "D"}, {900, "CM"}, {1000, "M"}};

            string res;
            int prev=1000;

            while(num>0){
                if(intToRoman.find(num)!=intToRoman.end()){
                    res+=intToRoman[num];
                    break;
                }
                for(auto x:intToRoman){
                    if(x.first<num) prev=x.first;
                }
                res+=intToRoman[prev];
                num-=prev;
            }

            return res;
    }
};