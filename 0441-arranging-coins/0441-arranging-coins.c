int arrangeCoins(int n){
// int i=1,count=0;
// while(n>0)
//     if(n-i>=i)
//     {
//     i++;
//     count++;
// }
// return count;
 long int sum=0,i=1,count=0;
while(sum<=n)
{
    sum=sum+i;
    i++;
    count++;
}
return count-1;
}