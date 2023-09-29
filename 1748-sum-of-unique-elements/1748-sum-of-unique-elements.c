int sumOfUnique(int* nums, int numsSize){
    int count,sum=0;
for(int t=0;t<numsSize;t++)
{  count=0;
for(int j=0;j<numsSize;j++)
    if(nums[t]==nums[j])
    count++;
if(count==1)
sum+=nums[t];
sum+=0;
}
return sum;
}
