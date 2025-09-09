class Solution {
    struct Compare{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.first<b.first;
        }
    };  
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>freq;

        int n=arr.size();

        for(const auto &it:arr) freq[it]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;

        for(const auto &[element,frequency]:freq){
            pq.push({frequency,element});
        }

        int count=0,currSize=0;
        while(!pq.empty() && currSize<n/2){
            pair<int,int>temp=pq.top();
            pq.pop();
            currSize+=temp.first;
            count++;
        }

        return count;
    }
};