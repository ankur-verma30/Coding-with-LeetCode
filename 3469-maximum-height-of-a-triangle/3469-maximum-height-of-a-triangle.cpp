class Solution {
public:
    int heightofTriangle(int red,int blue){
        int height=0;
        int i=1;
        bool useRed=true;
        while(true){
            if(useRed){
                if(i<=red) {
                    red=red-i; 
                }
                else break;
            }
            if(!useRed){
                if(i<=blue){
                     blue=blue-i;
                }
                else break;
            }
            if(useRed) useRed=false;
            else useRed=true;
            height++;
            i++;
            
        }
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int height1=heightofTriangle(red,blue);
        int height2=heightofTriangle(blue,red);
        
        return max(height1,height2);
    }
};