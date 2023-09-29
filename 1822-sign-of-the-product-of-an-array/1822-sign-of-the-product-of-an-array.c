int arraySign(int* nums, int numsSize){
  int product=1;
    for(  int i=0;i<numsSize;i++)  
    {
    if(nums[i]>0){
        nums[i]=1;
    }
        else
        if(nums[i]<0)
        {
            nums[i]=-1;
        }
    else
        nums[i]=0;
    product*=nums[i];
}
return product;
    }
       