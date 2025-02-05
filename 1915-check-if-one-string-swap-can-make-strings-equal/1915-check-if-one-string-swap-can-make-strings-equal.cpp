class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
          if(s1==s2) return true;
        int n=s1.length();
        unordered_map<char,int>mpp1,mpp2;
        int counter=0;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                counter++;
            }
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        if(counter>2) return false;

        cout<<counter<<endl;

        for(const auto &[element,freq1]:mpp1){
            int freq2=mpp2[element];
            if(freq1!=freq2) return false;
        }



        if(counter==2) return true;
        return false;
    }
};