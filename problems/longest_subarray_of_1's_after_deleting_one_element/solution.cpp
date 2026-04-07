class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int k=1;
        int cnt0=0;
        int maxl=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                cnt0++;
            }
            while(cnt0>k){
                if(nums[l]==0){
                    cnt0--;
                }
                l++;
            }
            maxl=max(maxl,r-l+1);
        }
        return maxl-1;
    }
};