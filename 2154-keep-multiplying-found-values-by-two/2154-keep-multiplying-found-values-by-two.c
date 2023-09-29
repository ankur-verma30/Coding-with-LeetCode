int findFinalValue(int* nums, int numsSize, int original){
    int temp,i,j;
    
  for ( i=0;i<numsSize-1; i++)
    for (j=0;j<numsSize-i-1;j++) {
      if (nums[j] >nums[j + 1]) {
        temp =nums[j];
        nums[j] =nums[j + 1];
        nums[j + 1] = temp;   } } 
    
    for( i=0;i<numsSize;i++) {
        if(nums[i]==original){
            original*=2;
        i=i--; } }
            return original;        
}
