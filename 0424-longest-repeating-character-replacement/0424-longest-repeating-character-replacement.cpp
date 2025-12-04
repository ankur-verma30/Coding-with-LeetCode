class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxFreq=0,n=s.length(),ans=0;
        unordered_map<char,int> freq;
        char ch;

        for(int right=0; right<n; right++){
            freq[s[right]]++;
            if(freq[s[right]]>maxFreq){
                maxFreq=freq[s[right]];
                ch=s[right];
            }
            if(right-left+1-maxFreq>k){
                char c=s[left];
                if(c==ch) maxFreq--;
                freq[s[left]]--;
                if(freq[s[left]]==0) freq.erase(s[left]);
                left++;
            }
            if(right-left+1-maxFreq<=k) ans=max(ans,right-left+1);
        }

        return ans;
    }
};