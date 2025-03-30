class Solution {
public:
    bool isPalindrome(string &str){
        int n=str.length();

        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1]) return false;
        }

        return true;
    }

    int longestPalindrome(string s, string t) {

        int n1=s.length(),n2=t.length();
        int maxLength=0;
        vector<string>subStringOfS,subStringOfT;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                string temp=s.substr(i,j-i+1);
                int len=temp.length();
                if(isPalindrome(temp)) maxLength=max(maxLength,len); 
                subStringOfS.push_back(temp);
            }
        }

         for(int i=0;i<n2;i++){
            for(int j=0;j<n2;j++){
                string temp=t.substr(i,j-i+1);
                int len=temp.length();
                if(isPalindrome(temp)) maxLength=max(maxLength,len);
                subStringOfT.push_back(temp);
            }
        }

        n1=subStringOfS.size(),n2=subStringOfT.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                string temp=subStringOfS[i]+subStringOfT[j];
                int len=temp.length();
                if(isPalindrome(temp)) maxLength=max(maxLength,len);
            }
        }
        return maxLength;
    }
};