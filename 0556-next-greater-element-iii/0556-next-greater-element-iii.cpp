class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        int len=str.size();
        bool isExist=false;

        stack<int>st;

        for(int i=len-1;i>=0;i--){
            int idx=i;
            while(!st.empty() && str[st.top()]>str[i]){
                idx=st.top();
                st.pop();
            }
            st.push(i);

            if(idx!=i){
                swap(str[idx],str[i]);
                isExist=true;
                sort(str.begin()+i+1,str.end());
                break;
            }
        }

        if(!isExist) return -1;

        long long res= stoll(str);
        if(res>INT_MAX) return -1;
        return res;
    }
};