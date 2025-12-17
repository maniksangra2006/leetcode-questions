class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=0;
        ans=ans+nums[0];
        sort(nums.begin()+1,nums.end());
        ans=ans+nums[1]+nums[2];
        return ans;
    }
};