class Solution {
public:
    string AddTwoString(string &ans,string str){
        if(ans.empty()) return str;
        int n1=ans.length(),n2=str.length();
        string res;
        int i=n1-1,j=n2-1,carry=0;
        while(i>=0 && j>=0){
            int val1=ans[i]-'0';
            int val2=str[j]-'0';
            int sum=val1+val2+carry;
            int rem=sum%10;
            cout<<"In function the value of rem "<<rem<<endl;
            res+=to_string(rem);
            carry=sum/10;
            i--;
            j--;
        }

        while(i>=0){
            int sum=(ans[i]-'0')+carry;
            int temp=sum%10;
             cout<<"In function the value of temp from ans "<<temp<<endl;
            res+=to_string(temp);
            carry=sum/10;
            i--;
        }

        while(j>=0){
            int sum=(str[j]-'0')+carry;
            int temp=sum%10;
             cout<<"In function the value of temp from str "<<temp<<endl;
            res+=to_string(temp);
            carry=sum/10;
            j--;
        }

        if(carry==1) res+='1';
        reverse(res.begin(),res.end());
        return res;
    }


    string multiply(string num1, string num2) {
      
       int n1=num1.length(),n2=num2.length();
       if(num1=="0" || num2=="0") return "0";

       if(n1<n2){
         swap(num1,num2);
         swap(n1,n2);
       }
       
        string ans;
        int count=0,carry=0;

       for(int i=n2-1;i>=0;i--){
        char ch=num2[i];
        int multiplier=ch-'0',carry=0;
        string str;
        for(int j=n1-1;j>=0;j--){
            char c=num1[j];
            int multiplicand=c-'0';
            int product=multiplier*multiplicand+carry;
            int rem=product%10;
            carry=product/10;
            str+=to_string(rem);
            
        }
        int temp=count;
        cout<<"Value of count "<<count<<endl;
        if(carry!=0) str+=to_string(carry);
        reverse(str.begin(),str.end());
        cout<<"Value of the iteration "<<i<< " value of string str "<<str<<endl;
        while(temp--) str+='0';
        cout<<"value of str "<<str<<endl;
        count++;
        ans=AddTwoString(ans,str);
        cout<<"ans after the "<<i<<"th iteration "<<ans<<endl;
       }

       if(carry!=0)ans=to_string(carry)+ans;
       return ans; 
    }
};