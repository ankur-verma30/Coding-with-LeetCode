class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int maxLength=0,left=0,right=0;
        int size=fruits.size();

        while(right<size){
            
             mp[fruits[right]]++;
            
            if(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;   
            }
            if(mp.size()<=2) maxLength=max(maxLength,right-left+1);
            right++;
        }

        return maxLength;
    }
};