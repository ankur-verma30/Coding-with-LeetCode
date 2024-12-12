class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int sum=0;

        for(const auto &pile:piles){
            pq.push(pile);
            sum+=pile;
        }

        while(k--){
            int element=pq.top();
            pq.pop();
            int halfElement=element/2;
            sum=sum-element;
            int diff=element-halfElement;
            sum+=diff;
            pq.push(diff);
        }

        return sum;

    }
};