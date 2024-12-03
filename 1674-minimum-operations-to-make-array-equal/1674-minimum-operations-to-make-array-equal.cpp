class Solution {
public:
    int minOperations(int n) {
            int count=0;
            int val=1;
            for(int i=1;i<=n/2;i++){
                    count+=(n-val);
                    val+=2;
            }

            return count;
    }
};