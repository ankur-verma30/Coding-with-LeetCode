class Solution {
public:
int CntBits(int n){
    int count=0;
    while(n>0){
        count+=(n&1);
        n=n>>1;
    }
    return count;
}
    vector<int> countBits(int n) {
        vector<int> v;
       for(int i=0;i<=n;i++){
         
    v.push_back(CntBits(i));
       }
       return v;
        
    }
};