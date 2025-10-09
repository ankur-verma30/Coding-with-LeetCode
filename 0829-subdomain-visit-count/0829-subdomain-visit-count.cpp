class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>freq;
        vector<string>ans;

        for(const string &str:cpdomains){
            int index=0,n=str.length();
            while(isdigit(str[index])) index++;
            string count=str.substr(0,index);
            int intCount=stoi(count);
            for(int i=n-1;i>=index+1;i-- ){
                if(str[i]=='.'){
                    string temp=str.substr(i+1);
                    if(freq.find(temp)!=freq.end()){
                        freq[temp]+=intCount;
                    }
                    else freq[temp]=intCount;
                }
            }
           string cpDomain=str.substr(index+1);
           freq[cpDomain]+=intCount;
        }

        for(const auto &[subDomain,count]:freq){
            ans.push_back(to_string(count)+" "+subDomain);
        }
        return ans;
        
    }
};