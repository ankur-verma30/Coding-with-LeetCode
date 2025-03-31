class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        int dominant=nums[0],count=0,n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==dominant) count++;
            else count--;
                if(count==0){
                    dominant=nums[i];
                    count=1;
                }
            
        }

        int freq=0;
        for(int i=0;i<n;i++) if(nums[i]==dominant) freq++;

        if(freq<=n/2) return -1;

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant) {
                total++;
                if (total * 2 > i + 1 && (freq - total) * 2 > (n - i - 1)) return i;
            }
        }
        return -1;
    }
};