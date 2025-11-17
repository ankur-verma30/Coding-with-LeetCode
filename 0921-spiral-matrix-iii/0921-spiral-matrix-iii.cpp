class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int steps=0,dir=0;
        int directionsx[]={0,1,0,-1};
        int directionsy[]={1,0,-1,0};
        
        vector<vector<int>>result;

        result.push_back({rStart,cStart});

        while((int)result.size()<rows*cols){
            if(dir==0 || dir==2) steps++;

            for(int count=0;count<steps;count++){
                rStart+=directionsx[dir];
                cStart+=directionsy[dir];

               if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                result.push_back({rStart, cStart});

            }
            dir=(dir+1)%4;

        }
        return result;
    }
};