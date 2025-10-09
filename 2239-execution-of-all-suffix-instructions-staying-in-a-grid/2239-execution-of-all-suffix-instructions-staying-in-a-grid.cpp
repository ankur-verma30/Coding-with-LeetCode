class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int moves=s.length();
        vector<int>ans;

        for(int i=0;i<moves;i++){
            int count=0;
            vector<int>start=startPos;
            for(int j=i;j<moves;j++){
                if(s[j]=='L') start[1]-=1;
                else if(s[j]=='R') start[1]+=1;
                else if(s[j]=='U') start[0]-=1;
                else if(s[j]=='D') start[0]+=1;

                if(start[0]<0 || start[0]>n-1 
                || start[1]<0 || start[1]>n-1) break;
                count++; 

            }
            ans.push_back(count);
        }
        return ans;
    }
};