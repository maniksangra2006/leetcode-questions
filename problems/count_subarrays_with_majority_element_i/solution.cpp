class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
          int n =nums.size();
        int ans=0;
        vector<int> num = nums;
         for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (num[j] == target) cnt++;
                int len = j - i + 1;
                if (cnt * 2 > len) ans++;
            }
        }
        return ans;
    }
};