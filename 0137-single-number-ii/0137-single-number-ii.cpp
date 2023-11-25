class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> SumArr(32,0);

        for(int x:nums)
        UpdateSum(SumArr,x);

        for(int i=0;i<32;i++)
        SumArr[i]%=3;

        return UniqueNumber(SumArr);
    }
    private:
    void UpdateSum(vector<int>&SumArr,int x){
        for(int i=0;i<32;i++){
            int ith_bit=x&(1<<i);
            if(ith_bit)
            SumArr[i]++;
        }
    }
    int UniqueNumber(vector<int> SumArr){
        int num=0;
        for(int i=0;i<32;i++)
        num+=(SumArr[i]*(1<<i));

        return num;
    }

};