class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n=s.length();
        if(k>n) return false;
       unordered_map<int,int>firstOccurance,lastOccurance;

       vector<pair<int,int>>intervals;

       for(int i=0;i<n;i++){
        if(firstOccurance.find(s[i])==firstOccurance.end()) firstOccurance[s[i]]=i;
        lastOccurance[s[i]]=i;
       } 

       for(int i=0;i<n;i++){
        if(i!=firstOccurance[s[i]]) continue;
        int left=firstOccurance[s[i]];
        int right=lastOccurance[s[i]];
        bool isValid=true;
        for(int index=left;index<=right;index++){
            right=max(right,lastOccurance[s[index]]);
            if(firstOccurance[s[index]]<left) isValid=false;
        }
        if(right-left+1<n && isValid) intervals.push_back({left,right});
       }

        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a.second<b.second; 
        });

        int count=0,lastEnd=-1;

        for(const auto &[start,end]:intervals ){
            if(start>lastEnd){
                count++;
                lastEnd=end;
            }
        }
        return count>=k ? true : false;


       
    }
};