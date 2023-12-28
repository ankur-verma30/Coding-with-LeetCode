/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
        let st=s+s;
        let len=goal.length;

        let value=false;

        for(let i=0;i<st.length;i++){
           let str=st.substring(i,i+len);
           if(str==goal && (str.length===(st.length/2))) {     
                value=true;
                break; 
        }
        else 
        value=false;
        }
        return value;
    }