class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstWordSum=SumOfStringValue(firstWord);
        int secondWordSum=SumOfStringValue(secondWord);

        int targetWordSum=SumOfStringValue(targetWord);

        return ((firstWordSum+secondWordSum)==targetWordSum)?true:false;
    }
    private:

    int SumOfStringValue(string s){
        int value=0;
        for(int i=0;i<s.length();i++){
            int n=s[i]-'a';
            value=value*10+n;
        }
        return value;
    }
};