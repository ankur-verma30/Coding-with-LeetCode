class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(),count=0;

        vector<bool>isPlaced(n,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!isPlaced[j] && fruits[i]<=baskets[j]){
                    isPlaced[j]=true;
                    count++;
                    break;
                }
            }
        }
        return n-count;
    }
};