class Solution {
public:
    int searchMaxBeauty(vector<vector<int>>&items,vector<int>&maxBeauty,int q){
        int low=0,high=items.size()-1;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(items[mid][0]<=q){
                ans=maxBeauty[mid];
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());

        int n=items.size();

        vector<int>maxBeauty(n,0);

        maxBeauty[0]=items[0][1];
               for(int i=1;i<n;i++){
            maxBeauty[i]= max(maxBeauty[i-1],items[i][1]);
        }

        vector<int>ans;

        for(auto query:queries){
            ans.push_back(searchMaxBeauty(items,maxBeauty,query));
        }

        return ans;


    }
};