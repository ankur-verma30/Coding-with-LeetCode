int findNumbers(int* nums, int numsSize){
int digits=0,count;
for(int i=0;i<numsSize;i++)
{count=0;
    while(nums[i]>0)
    {
        nums[i]/=10;
        count++;
    }
    if(count%2==0)
    digits++;
}
return digits;
}