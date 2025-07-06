class FindSumPairs {
public:
    vector<int>n1,n2;
    unordered_map<int,int>freqN2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
          for(const auto it:n2) freqN2[it]++;
    }
    
    void add(int index, int val) {
        freqN2[n2[index]]--;
        n2[index]+=val;
        freqN2[n2[index]]++;
    }
    
    int count(int tot) {
        int countAns = 0;
      
      

        for(const auto num:n1){
            if(num>tot) continue;
            if(freqN2.find(tot-num)!=freqN2.end()){
                countAns+=freqN2[tot-num];
            }
        }
   
        
    return countAns;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */