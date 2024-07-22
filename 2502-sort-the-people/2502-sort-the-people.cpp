class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
          map<int,string,greater<int>>mp;
        
        for(int i=0;i<names.size();i++){
            mp[heights[i]]=names[i];
        }

        vector<string>name;
        for(auto x:mp) name.push_back(x.second);

        return name;
    }
};