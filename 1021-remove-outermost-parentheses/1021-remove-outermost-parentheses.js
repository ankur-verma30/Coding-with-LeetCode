/**
 * @param {string} s
 * @return {string}
 */
var removeOuterParentheses = function(s) {
      let res="";
     let count=0;
        for(let i=0;i<s.length;i++){
            if(s[i]=='(' && count==0)
                count++;
            else if(s[i]=='(' && count>=1){
                res+=s[i];
                count++;
            }   
            else if(s[i]==')' && count>1){
                res+=s[i];
                count--;
            }
            else if(s[i]==')' && count==1)
                count--;
        }
        return res;
};