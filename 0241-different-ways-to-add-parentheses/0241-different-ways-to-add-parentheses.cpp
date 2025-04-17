class Solution {
public:
    vector<int>solve(string exp){
        vector<int>result;

        for(int i=0;i<exp.length();i++){
            if(exp[i]=='*' || exp[i]=='-'|| exp[i]=='+'){
                vector<int>left_part=solve(exp.substr(0,i));
                vector<int>right_part=solve(exp.substr(i+1));

                for(int &val1:left_part){
                    for(int &val2:right_part){
                        if(exp[i]=='*')result.push_back(val1*val2);
                        else if(exp[i]=='-') result.push_back(val1-val2);
                        else result.push_back(val1+val2);
                    }
                }
            }
        }
        if(result.empty()) return {stoi(exp)};
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};