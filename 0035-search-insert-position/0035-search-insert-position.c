int searchInsert(int* nums, int numsSize, int target){
  for( long int i=0;i<numsSize;i++){
    if(nums[i]==target)
    {
   return i;   
    }
        else if(target<nums[i])
        {
        return i;
        }
        else if(target>nums[numsSize-1])
        {
          return numsSize;
        }
}
    return 0;
}