class Solution {
public:
    double trimMean(vector<int>& arr) 
    {
        int num=(arr.size())* (5.0/100.0);
        sort(arr.begin(),arr.end());
        double sum=0;
        int count=0;
        
        for(int i=0+num;i<arr.size()-num;i++)
        {
            sum=sum+arr[i];
            count++;
        }
        return sum/count;
       
    }
};