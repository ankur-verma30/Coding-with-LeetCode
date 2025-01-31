struct comparator{
    bool operator()(const pair<string,int>&a,const pair<string,int>&b){
        if(a.second!=b.second) return a.second<b.second;
        return a.first<b.first;
    }
};
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>mpp;
        int n=messages.size();

        for(int i = 0; i <n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < messages[i].size(); j++)
            {
                if(messages[i][j] == ' ')
                    cnt++;
            }
            mpp[senders[i]] += cnt + 1;
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,comparator>pq;

        for(const auto &[word,freq]:mpp){
            pq.push({word,freq});
        }

        return pq.top().first;
    }
};