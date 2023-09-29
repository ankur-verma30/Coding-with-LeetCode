class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> count;
    vector<int> newCount;

      for(int i=0;i<arr.size();i++){
      count[arr[i]]++; //counting occurrence of each element
      }
      for( auto x:count)
      newCount.push_back(x.second);//listing count of each element in the list

      sort(newCount.begin(),newCount.end());//sort the list

      for(int i=0;i<newCount.size()-1;i++)//finding no two adjacent element is equal
      {
        if(newCount[i]==newCount[i+1])
        return false;
      }
return true;
    }
};