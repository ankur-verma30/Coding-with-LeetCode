class Solution {
public:
    int passThePillow(int n, int time) {
        
        /*
        int rem_passes = time%(n-1);
        
        if((time/(n-1))%2==0){
            return rem_passes+1;
        }
        return n-rem_passes;
        
        */
        int count=1, index=1;
        bool direction=true;
        while(count<=time)
        {
            if(index==n) direction=false;
            else if(index==1) direction=true;
            
            count++;
            
            if(direction)   index++;
            else  index--;
        }
        return index;
        }
};