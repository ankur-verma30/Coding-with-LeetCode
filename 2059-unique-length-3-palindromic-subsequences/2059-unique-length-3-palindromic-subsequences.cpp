class Solution {
public:
    int countPalindromicSubsequence(string s) {
    vector<int>firstOccurance(26,INT_MAX),lastOccurance(26,0);


    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(firstOccurance[ch-'a']==INT_MAX) firstOccurance[ch-'a']=i;
        lastOccurance[ch-'a']=i;
    }   

    int count=0;
    for(int i=0;i<26;i++){
        if(firstOccurance[i]==INT_MAX) continue;
        int start=firstOccurance[i]+1;
        int end=lastOccurance[i];
        set<char>st;
        for(int j=start;j<end;j++) st.insert(s[j]);
        count+=(int)st.size();
    } 

    return count;
    }
};