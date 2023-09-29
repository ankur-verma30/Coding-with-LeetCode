int subtractProductAndSum(int n){
int pro=1 ,sum=0,rem;
while(n>0)
{
    rem=n%10;
    n=n/10;
    pro=pro*rem;
    sum=sum+rem;
}
return (pro-sum);
}