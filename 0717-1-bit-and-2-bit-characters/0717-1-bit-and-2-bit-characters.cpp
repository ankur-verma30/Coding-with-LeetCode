class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool lastOneBit=false;
        bool lastTwoBit=false;
        int n=bits.size();

        for(int i=0;i<n;i++){
                if(bits[i]==0){
                    lastOneBit=true;
                    lastTwoBit=false;
                }
                else if(bits[i]==1) {
                    lastTwoBit=true;
                    lastOneBit=false;
                    i++;
                } 
        }
        return (lastOneBit) ? true :false;

    }
};