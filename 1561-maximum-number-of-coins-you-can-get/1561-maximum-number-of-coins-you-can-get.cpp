class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(piles.begin(),piles.end(),greater<int>()); //O(nlogn)

        int left=1,right=piles.size()-1;

        int coinCount=0;

        while(left<right){          //O(log2n)
            coinCount+=piles[left];
            left=left+2;
            right--;
        }
        return coinCount;
    }
};