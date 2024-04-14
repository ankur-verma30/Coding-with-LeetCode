class Solution {
public:
    int minimumSum(int num) {
      vector<int>splitDigit;

      while(num>0){
        int rem=num%10;
        splitDigit.push_back(rem);
        num=num/10;
      }  

      sort(splitDigit.begin(),splitDigit.end());

      int left=0,right=splitDigit.size()-1;
    int sum=0;
      while(left<right){
        int n=splitDigit[left++]*10+splitDigit[right--];
        sum+=n;
      }

      return sum;
    }
};