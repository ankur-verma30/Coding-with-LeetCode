class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        auto it1=g.begin();
        auto it2=s.begin();   
          
          int count=0;

        while(it1!=g.end() && it2!=s.end()){
            if(*it1<=*it2)
            {
                count++;
                it1++;
                it2++;
            }
            else if(*it1>*it2){
                it2++;
            }
        }
      return count;
    }
};