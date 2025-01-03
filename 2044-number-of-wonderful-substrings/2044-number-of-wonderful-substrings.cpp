class Solution {
public:
    long long wonderfulSubstrings(string word) {
       unordered_map<long long,long long>freq;

       freq[0]=1;

       long long prefixPattern=0,ans=0;

       for(auto ch:word){
        prefixPattern=(prefixPattern ^ (1<<(ch-'a')));
        ans+=freq[prefixPattern];

       for(auto c='a';c<='j';c++){
        long long oddPattern=(prefixPattern ^(1<<(c-'a')));
        ans+=freq[oddPattern];
       }

       freq[prefixPattern]++;
    }
    return ans;
    }
};