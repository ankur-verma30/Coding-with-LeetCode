class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>result;
    
    for(int i=0;i<n/2;i++){
        result.push_back(i+1);
        result.push_back(-(i+1));    
    }
    if(n%2!=0)
        result.push_back(0);
    
    sort(result.begin(),result.end());
    
    return result;
}
    
};