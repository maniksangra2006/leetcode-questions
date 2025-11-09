class Solution {
public:
    int minimumDistance(vector<int>& nums) {
         int n = nums.size();
        int minDist = INT_MAX;
         for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
                        minDist = min(minDist, dist);
                    }
                }
            }
        }
         return (minDist == INT_MAX) ? -1 : minDist;
    }
};