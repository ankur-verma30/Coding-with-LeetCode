class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
           int len=arr.size(); //size of the array
        int low=1,high=len-2;
        
        
        if(arr[len-1]>arr[len-2])//if peak is last element
            return len-1;
        
       
        
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[mid+1] &&arr[mid]>arr[mid-1])
                return mid;
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};