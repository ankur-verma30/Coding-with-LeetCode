class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
      long long sum=0;
      int n=skills.size();

      for(auto &x:skills) sum+=x;

      long long target= (2*sum)/n;

      unordered_map<int,int>mpp;
    vector<pair<int,int>>res;

      for(auto &x:skills){
        if(mpp.find(target-x)!=mpp.end() && target){
            res.push_back({target-x,x});
            mpp[target-x]--;
            if(mpp[target-x]==0) mpp.erase(target-x);
        }
        else mpp[x]++;
      }
      if(res.size()!=n/2) return -1;
    long long pro=0;
      for(auto &x:res){
        pro+=(x.first*x.second);
      }

      return pro;

    }
};