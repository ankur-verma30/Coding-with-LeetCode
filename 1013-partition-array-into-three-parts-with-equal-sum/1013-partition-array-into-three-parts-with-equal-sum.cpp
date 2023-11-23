class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total=0;
        for(int i=0;i<arr.size();i++)
        total+=arr[i];

       if(total%3!=0)
       return false;
       
       int partialValue=total/3;
       int sum=0,count=0;

       for(int i=0;i<arr.size();i++){
           sum+=arr[i];
           if(sum==partialValue){
              count++;
              sum=0;
           }
              if(count==3){
              return true;
              break;
              }
           
       }
       return false;
      
    }
};