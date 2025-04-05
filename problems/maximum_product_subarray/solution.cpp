class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int ans = nums[0];
    int pre = 1, suff = 1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Calculate prefix product
        pre = (pre == 0 ? 1 : pre) * nums[i];

        // Calculate suffix product
        suff = (suff == 0 ? 1 : suff) * nums[n - i - 1];

        // Update the maximum product
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

        

    
};