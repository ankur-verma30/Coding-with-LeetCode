class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    int minAnagramLength(string s) {
        unordered_map<char, int> freq;
    
    // Count frequency of each character in the string
    for (char c : s) {
        freq[c]++;
    }
        if(freq.size()==s.length()) return s.length();
     
    // Calculate LCM of frequencies
        int result=0;
    for (auto& p : freq) {
        result = gcd(result, p.second);
    }
    
    return s.length()/result;
    }
};