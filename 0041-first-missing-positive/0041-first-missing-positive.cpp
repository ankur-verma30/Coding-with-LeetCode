class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    

         //Brute force Method T.C O(2N)  S.C.O(N)

         map<int,int>counter;

    for(int i=0; i<nums.size();i++)
        counter[nums[i]]++;

        int count=1;
    for(int i=0;i<nums.size();i++){
            if(counter[count]==0)
            return count;
            else 
            count++;
        }
        return count;
        

        //We have to solve in T.C. O(N)  and S.C  O(1)
        
    }
};