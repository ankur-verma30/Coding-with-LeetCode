class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
       int FirstCount=0,SecondCount=0;
        
        for(int i=0;i<n/2;i++){
            if(IsVowel(s[i])) FirstCount++;
            if(IsVowel(s[n-1-i])) SecondCount++;
            
        }
        return (FirstCount==SecondCount)?true:false;
        
    }
    
    private:
    bool IsVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        
        return false;
            
    }
};