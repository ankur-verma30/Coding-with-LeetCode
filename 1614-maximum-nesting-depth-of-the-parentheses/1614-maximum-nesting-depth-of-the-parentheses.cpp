/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(s) {
       let count=0,Depth=0;

     for(let i=0;i<s.length;i++){
         if(s[i]==='(' ){
             count++;
             Depth=Math.max(count,Depth);
         }
         else if(s[i]===')' && count>=1)
         count--;
     }   
     return Depth;
};