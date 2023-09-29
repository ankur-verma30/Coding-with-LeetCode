/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    int* result =malloc(sizeof(int )*numsSize);
int temp,len=0;
for(int i=0;i<numsSize-1;i++)
for(int j=0;j<numsSize-i-1;j++)
if(nums[j+1]<nums[j])
{
     temp=nums[j];
    nums[j]=nums[j+1];
    nums[j+1]=temp;
}

for(int i=0;i<numsSize;i++)
if(nums[i]==target)
{
    result[len]=i;
    len++;
}
*returnSize=len;
return result;
}