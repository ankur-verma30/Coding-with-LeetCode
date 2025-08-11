class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if((n &(n-1))==0) return true;

        string str=to_string(n);
        sort(str.begin(),str.end());

            do{
            if(str[0]=='0') continue;
            int num=stoi(str);
            cout<<num<<'\n';
             if((num &(num-1))==0) return true;
        }while(next_permutation(str.begin(),str.end()));

        return false;
    }
};