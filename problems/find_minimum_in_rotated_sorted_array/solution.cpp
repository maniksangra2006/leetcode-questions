class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       
        int n=nums.size();
         for(int i=0;i<n;i++){
             if(i==0){
             return nums[i];
             }
         }
        return -1;
    }
};