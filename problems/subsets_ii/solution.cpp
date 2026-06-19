class Solution {
public:
 void findSubsets(int idx,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx&& nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            findSubsets(i+1,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,curr,ans);
        return ans;
    }
};