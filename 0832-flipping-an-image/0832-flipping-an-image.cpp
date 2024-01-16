class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
     int length=image.size();

     for(int i=0;i<length;i++){
         for(int j=0;j<length/2;j++){
             swap(image[i][j],image[i][length-1-j]);
         }
     }   

     for(int i=0;i<length;i++){
         for(int j=0;j<length;j++){
             if(image[i][j]==0) image[i][j]=1;
             else
             image[i][j]=0;
         }
     }
     return image;
    }
};