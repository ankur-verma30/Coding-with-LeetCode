class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>stk;
        vector<int>answer(temp.size(),0);
        
        for(int i=0;i<temp.size();i++){
            while(!stk.empty() && temp[stk.top()]<temp[i]){
               int stackTop=stk.top();
               stk.pop();
                answer[stackTop]=i-stackTop;
            }
            stk.push(i);
        }
        return answer;
    }
};