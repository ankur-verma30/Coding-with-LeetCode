class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>freq;

        for(const auto &ch:s) freq[ch]++;

        priority_queue<char>pq;

        for(const auto &[ch,fr]:freq) pq.push(ch);

        char repeatWord='#';

        string res="";
        while(!pq.empty()){
            int limit=repeatLimit;
            char ele=pq.top();
            pq.pop();
            if(repeatWord!='#'){
                res+=ele;
                freq[ele]--;
                if(freq[ele]==0) freq.erase(ele);
                else pq.push(ele);
                pq.push(repeatWord);
                repeatWord='#';
                continue;
            }
            int count=freq[ele];
            if(count<=limit){
                for(int i=0;i<count;i++) res+=ele;
                freq.erase(ele);
            }
            else {
                int used=min(limit,count);
                for(int i=0;i<used;i++) res+=ele;
                freq[ele]=count-used;
                if(repeatWord=='#') repeatWord=ele;

            }
        }

        return res;
    }
};