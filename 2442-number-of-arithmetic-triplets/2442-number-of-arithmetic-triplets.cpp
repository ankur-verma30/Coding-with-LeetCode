class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size(),i=0,count=0;


        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++ ){
                    if((nums[j]-nums[i]==diff) && (nums[k]-nums[j]==diff)) count++;
                }
            }
        }

        

        // while(i<n-2){
        //     int j=i+1,k=n-1;
        //     if(nums[j]-nums[i]==diff){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[k]-nums[j]>diff) break;
        //             else if(nums[k]-nums[j]==diff) count++;
        //         }
        //     }
        //     else if(nums[j]-nums[i]<diff) j++;
        //     else if(nums[j]-nums[i]>diff) i++;
        // }

        return count;
    }
};