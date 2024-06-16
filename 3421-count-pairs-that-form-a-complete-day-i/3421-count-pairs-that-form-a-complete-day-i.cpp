class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        
        int count=0;
        sort(hours.begin(),hours.end());
        
        for(int i=0;i<hours.size();i++){
            
            for(int j=i+1;j<hours.size();j++){
                
                if((hours[i]+hours[j])%24==0) count++;
            }
        }
        return count;
    }
};