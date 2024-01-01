class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count=0,i=0,j=0;

        while(i<(int)g.size() && j<(int)s.size()){
            if(s[j]>=g[i]){
                i++;
                j++;
                count++;
            }
            else if(s[j]<g[i]){
                j++;
            }
        }

        return count;

        
    }
};