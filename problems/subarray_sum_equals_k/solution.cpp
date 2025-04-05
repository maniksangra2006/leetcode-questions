class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        mpp[0] = 1;
        int currSum = 0;
        int count = 0;

        for(int num : nums) {
            currSum = currSum + num;

            if(mpp.find(currSum-k) != mpp.end()) {
                count += mpp[currSum - k];
            }

            mpp[currSum]++;
        }

        return count;
    }
};