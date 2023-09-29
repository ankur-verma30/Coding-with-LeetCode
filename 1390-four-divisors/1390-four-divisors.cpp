class Solution {
public:
     inline int sum(int num){
          int n =0,count =0;
          for(int i =2;i<num;i++){
              if(num%i==0){
                  count++;
                  n+=i;
              }
              if(count>=3){
                  n =0;
                  break;
              }
          }
          if(count ==2){
              return n +1+num;
          }
          return 0;
      }
    int sumFourDivisors(vector<int>& nums) {
         int ans =0;
       for(int i=0;i<nums.size();i++){
            ans += sum(nums[i]);
       } 
       return ans;
    }
};

        /*

        This method has some issues
         int ans =0;
         int n =0,count =0,num=0,sum=0;

       for(int i=0;i<nums.size();i++){
           num=nums[i];
           count=0;
           n=0;
           sum=0;
          for(int i =2;i<num;i++){
              if(num%i==0){
                  count++;
                  n+=i;
              } 
              if(count>=3){
                  n =0;
                  break;
              }
          if(count ==2)
              sum=n+1+num; 
          }
          
            ans += sum;
       } 
       return ans;
    }  */
