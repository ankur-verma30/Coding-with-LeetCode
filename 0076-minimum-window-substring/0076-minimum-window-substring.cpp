class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        if(s.length()<t.length()) return "";

        int Slen=s.size();
        int Tlen=t.size();

        unordered_map<char,int>map1,map2;

        for(int i=0;i<Tlen;i++) map1[t[i]]++;

        int left=0,right=0,minleft=0,count=0;
        int minLength=INT_MAX;

        for(int right=0;right<Slen;right++){
            char c=s[right];

            //skip the characters that is not present in the string t
            if(map1.count(c)==0) continue;

            //increment the count of matching characters in the next ma
            map2[c]++;

            if(map2[c]<=map1[c]) count++;

            if(count==Tlen){
                //now we got the answer try to minimize the window
                while(map1.count(s[left])==0 || map2[s[left]]>map1[s[left]]){
                    if(map2.count(s[left])!=0) map2[s[left]]--;
                    left++;
                }
                if(right-left+1<minLength){
                    minLength=right-left+1;
                    minleft=left;
                }
            }
        }

        //if no valid window found return empty string
        if(minLength==INT_MAX) return "";


        //substring from left to minlength 
        return s.substr(minleft,minLength);
    }
};