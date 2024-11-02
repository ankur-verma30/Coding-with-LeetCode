class Solution {
public:
    bool isCircularSentence(string sen) {
        if(sen[0]!=sen[sen.length()-1]) return false;
        stringstream ss(sen);
    string Word;

    vector<char>temp;
    while (ss >> Word){
      temp.push_back(Word[0]);
      temp.push_back(Word[Word.length()-1]);
    }
    
    int n=temp.size();
    for(int i=1;i<n-1;i+=2){
       if(temp[i]!=temp[i+1]) return false;
    }

    return true;
    }
};