class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        //Not the optimal solution operation can be reduced 
        reverse(nums.begin(),nums.end());
        stack<int> st;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            count++;
            else
            st.push(nums[i]);
        }

        for(int i=0;i<nums.size();i++)
        if(!st.empty()){
            nums[i]=st.top();
            st.pop();
        }
        else if(count!=0){
            nums[i]=0;
            count--;
        }
        
    }
};