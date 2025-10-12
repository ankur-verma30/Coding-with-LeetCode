class Solution {
public:
    int longestBalanced(string s) {
        //v1=aCount-bCount, v2=cCount-bCount;
      int n=s.length(),ans=1,v1=0,v2=0;

      map<pair<int,int>,int> mp;
      mp[{0,0}]=-1;  

    // containing 3 characters
      for(int i=0;i<n;i++){
        if(s[i]=='a') v1++;
        else if(s[i]=='c') v2++;
        else {
            v1--;
            v2--;
        }
        if(!mp.count({v1,v2})) mp[{v1,v2}]=i;
        else ans=max(ans,i-mp[{v1,v2}]);
      }

      //containing any two characters
      vector<string>combinations{"ab","ac","bc"};

      for(const auto &combination:combinations){
        int x=combination[0],y=combination[1],v=0;
        map<int,int>m;
        m[0]=-1;

        for(int i=0;i<n;i++){
            if(s[i]==x) v++;
            else if(s[i]==y) v--;
            else{
                m.clear();
                v=0;
            } 
            if(!m.count(v)) m[v]=i;
            else ans=max(ans,i-m[v]);
        }
      }

      //for singleCharacter
      int count=1;
      for(int i=1;i<n;i++){
        if(s[i-1]==s[i]) count++;
        else count=1;
        ans=max(ans,count);
      }

      return ans;
    }
};