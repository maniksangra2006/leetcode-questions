class Solution {
public:
vector<vector<int>> res;
vector<int> ans;
void backtrack(vector<int> & nums,int strt){
    res.push_back(ans);
    for(int i=strt;i<nums.size();i++){
    ans.push_back(nums[i]);
        backtrack(nums,i+1);
        ans.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        ans.clear();
        backtrack(nums,0);
        return res;
    }
};