class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
          
        long long vol=(long long)(length)*(long long)(width)*(long long)height;//VOLUME

			bool bulky= (vol>=1e9 || (length>=1e4 || width>=1e4 || height>=1e4));

        bool heavy = (mass >= 100);

        if (bulky && heavy)
            return "Both";
        else if (bulky)
            return "Bulky";
        else if (heavy)
            return "Heavy";
        else
            return "Neither";
    }
};