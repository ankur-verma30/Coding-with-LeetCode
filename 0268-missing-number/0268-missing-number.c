int missingNumber(int* nums, int numsSize){
int sum=0,Sum=0;
sum=((numsSize)*(numsSize+1))/2;
for(int i=0;i<numsSize;i++)
Sum+=nums[i];
return sum-Sum;
}