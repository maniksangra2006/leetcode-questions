class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int  n=nums.size();
     int startingPOS=-1;
     int endingPOS=-1;
     for(int i=0;i<n;i++){
        if(nums[i]==target){
            startingPOS=i;
            break;
        }
     }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                endingPOS =i;
                break;
            }

        
     }
     return{startingPOS,endingPOS};
    }
};