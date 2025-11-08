class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt += maxVal-nums[i];
        }
        return cnt;
    }
};
