class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
         
        int max=*max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());
        long long ans=max-min;
        return ans*k;
    }
};