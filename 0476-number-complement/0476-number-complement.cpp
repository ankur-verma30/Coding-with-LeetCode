class Solution {
public:
    int findComplement(int num) {
       for(int i=0;i<countbits(num);i++)
        {
            num=num^(1<<i);
        }
        return num;
    }
    private:
    int countbits(int n){
    int count=0;
    while(n>0){
        count++;
        n=n>>1;
    }
    return count;
}
};