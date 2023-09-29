int maxProductDifference(int* nums, int numsSize){
int temp,diff=0;
for(int i=0;i<numsSize-1;i++)
    for(int j=0;j<numsSize-i-1;j++)
    if(nums[j]>nums[j+1])
    {
    temp=nums[j];
    nums[j]=nums[j+1];
    nums[j+1]=temp;
    }
    diff=((nums[numsSize-1]*nums[numsSize-2])-(nums[0]*nums[1]));
    return diff;
}