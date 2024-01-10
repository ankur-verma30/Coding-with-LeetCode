class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        
          int i = 0, j = 0;
          int n=arr.size();

          if(n==1)  return arr;

        while (i < n) {

            if (arr[i] % 2 == 0){
                swap(arr[i], arr[j]);
                j++;
            }
            i++;
        }
    
        return arr;
    }
};