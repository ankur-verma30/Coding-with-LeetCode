class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        bool result;
        sort(arr.begin(),arr.end());
        int len=arr.size();

        for(int i=0;i<len-2;i++){
            if(double(arr[i]+arr[i+2])/2==(double)arr[i+1])
            result=true;
            else
            {
                result=false;
                break;
            }
           
        }
        return result;
    }
};