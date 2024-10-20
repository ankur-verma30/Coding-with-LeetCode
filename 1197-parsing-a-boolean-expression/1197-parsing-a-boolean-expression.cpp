class Solution {
public:
    bool FindVal(vector<char>&values,char val){
        for(int i=0;i<values.size();i++){
            if(values[i]==val) return true;
        }
        return false;
    }
    char evaluate(vector<char>&values,char op){
        if(op=='&'){
            if(FindVal(values,'f')) return 'f';
            else return 't';
        }
        else if(op=='|'){
            if(FindVal(values,'t')) return 't';
            else return 'f';
        }
        else {
            return (values[0]=='f')?'t':'f';
        }
    }
    bool parseBoolExpr(string exp) {
        int n=exp.length();
        stack<char>st;
        
        for(int i=0;i<n;i++){
            char ch=exp[i];
            vector<char>values;
            char op;
            if(ch==')'){
               while(st.top()!='('){
                 char val=st.top();
                st.pop();
                values.push_back(val);
               }
               st.pop();
               op=st.top();
               st.pop();
               char res=evaluate(values,op);
               st.push(res);
            }
            else{
                if(ch!=',') st.push(ch);
            }
        }
    return st.top()=='t';
    }
};