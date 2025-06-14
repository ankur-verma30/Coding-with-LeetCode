class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string str2=to_string(num);

        for(const auto &it:str){
            if(it=='9') continue;
            else{
                char ch=it;
                for(auto &it2:str){
                    if(ch==it2) it2='9';
                } 
                break;
            }
        }
        int maxNum=stoi(str);
        cout<<maxNum<<endl;

        for(const auto &it:str2){
            if(it=='0') continue;
            else{
                char ch=it;  //ch==1
                for(auto &it2:str2){
                    if(ch==it2) it2='0';
                } 
                break;
            }
        }

        int minNum=stoi(str2);

        cout<<minNum<<endl;

        return maxNum-minNum;

    }
};