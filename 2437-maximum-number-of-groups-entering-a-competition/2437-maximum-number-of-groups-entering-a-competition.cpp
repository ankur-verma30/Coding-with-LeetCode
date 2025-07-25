class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
           if(n==1) return 1;
        sort(grades.begin(),grades.end());

        int initialSize=1,currSize=0,initialScore=grades[0], currScore=0,totalGroupCount=1;


        for(int i=1;i<n;i++){
            currScore+=grades[i];
            currSize++;
            if(currScore>initialScore && currSize>initialSize){
                initialScore=currScore;
                initialSize=currSize;
                totalGroupCount++;
                currSize=0;
                currScore=0;
            }
        }
        return totalGroupCount;
    }
};