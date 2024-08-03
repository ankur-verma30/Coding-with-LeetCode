class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        int n=target.size();
        int m=arr.size();

        if(n!=m) return false;

        for(int i=0;i<n;i++){
            if(arr[i]!=target[i]) return false;
        }

        return true;
    }
};