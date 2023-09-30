int findGCD(int* nums, int numsSize){
int min,max,k=0;
      min=nums[0];
     max=nums[0];
    for(int i=0;i<numsSize;i++){
    {
      
        if(nums[i]>=max)
            max=nums[i];
    if(min>=nums[i])
        min=nums[i];
    }
}
for(int i=1;i<=min;i++)
{
    if(min%i==0&&max%i==0)
        k=i;
    }
       return k; 
}