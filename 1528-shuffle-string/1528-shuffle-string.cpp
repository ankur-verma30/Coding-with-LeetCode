class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
           string result=s;

     for(int i=0;i<indices.size();i++)
     result[indices[i]]=s[i];

     return result;
    }


        /*
     map<int,char> mp;
      int z=0;
     string r="";

      for(int i=0;i<indices.size();i++)
          mp[indices[i]]=s[i];

      for(auto x:mp)
      {
          if(z==x.first)
        {
            r+=x.second;
            z++;
        }
          else 
          continue;
      }  
      return r;
      */

    
};