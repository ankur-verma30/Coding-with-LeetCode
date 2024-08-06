class Solution {
public:
static bool compare(const pair<char,int>pair1,const pair<char,int>pair2){
    return pair1.second>pair2.second;
 }
    int minimumPushes(string word) {
       unordered_map<char,int>wordCount;
       vector<pair<char,int>>words;

       for(auto& x:word) wordCount[x]++;

       for(auto& x:wordCount){
        pair<char,int>temp={x.first,x.second};
        words.push_back(temp);
       }

       sort(words.begin(),words.end(),compare);

       int i=1,count=1,minpush=0;


       for(auto x:words){
        if(count>8){
            count=1;
            i++;
        }
        minpush+=(x.second*i);
        cout<<minpush<<endl;
        count++;
        
       }
       return minpush; 
    }
};