class Solution {
public:
    bool isCircularSentence(string sen) {
        int n=sen.length();
        if(sen[0]!=sen[n-1]) return false;
    //     stringstream ss(sen);
    // string Word;

    // vector<char>temp;
    // while (ss >> Word){
    //   temp.push_back(Word[0]);
    //   temp.push_back(Word[Word.length()-1]);
    // }
    
    // int n=temp.size();
    // for(int i=1;i<n-1;i+=2){
    //    if(temp[i]!=temp[i+1]) return false;
    // }

    for(int i=1;i<n-1;i++){
        if(sen[i]==' '){
            if(sen[i-1]!=sen[i+1]) return false;
        }
    }
    return true;
    }
};