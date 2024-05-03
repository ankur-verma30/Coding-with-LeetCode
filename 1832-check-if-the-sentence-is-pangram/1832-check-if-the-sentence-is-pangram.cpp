class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int>mpp;

        for(auto x:sentence) mpp[x]++;

    return (mpp.size()==26)?true:false;
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);