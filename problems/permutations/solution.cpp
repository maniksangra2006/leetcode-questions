class Solution {
public:
  
    vector<vector<int>> permute(vector<int> nums) {
       vector<vector<int>> ans;
        
        // 1. Sort the string to start from the lexicographically smallest permutation
        sort(nums.begin(), nums.end());
        
        // 2. Keep finding the next permutation until no more exist
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};