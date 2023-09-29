int averageValue(int* nums, int numsSize){
    int count=0,total=0;
for(int i=0;i<numsSize;i++)
{
    if(nums[i]%6==0)
    {
        total+=nums[i];
    count++;
    }
    
}
    if(count==0)
        return 0;
    else
    return total/count;
    return 0;
}