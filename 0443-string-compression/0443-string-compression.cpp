class Solution {
public:
     void digits(char ch, int& start, vector<char>& chars, int freqlen) {
        string freqStr = to_string(freqlen);
        chars[start++] = ch;
        for (char digit : freqStr) {
            chars[start++] = digit;
        }
    }

    int compress(vector<char>& chars) {
        int n = chars.size(), freq=0;
        char ch=chars[0];
        int start=0;
        for(int i=0;i<n;i++){
            if(chars[i]==ch) freq++;
            else{
                 if (freq == 1) chars[start++] = ch;
             else  digits(ch, start, chars, freq);
                ch=chars[i];
                freq=1;
            }
        }

          if (freq == 1) {
            chars[start++] = ch;
        } else {
            digits(ch, start, chars, freq);
        }

        chars.resize(start);
        return chars.size();
    }

};