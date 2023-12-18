class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) { 
    int n=nums.size();
    long long int Concatenation=0;

    if(n==1)  return nums[0];

    for(int i=0; i<n/2; i++){
        int firstValue=nums[i];
        int lastValue=nums[n-1-i];
        int count=DigitCount(lastValue);
        while(count--){
            firstValue*=10;
        }
        Concatenation+=(lastValue+firstValue);    
    }
      if(n%2!=0)  Concatenation+=nums[n/2];

      return Concatenation;
    }
    private:

    int DigitCount(int n){
      int count=0;
      while(n>0){
        n=n/10;
        count++;
    }
    return count;
}
};