class Solution {
public:
vector<vector<int>> res;
vector<int> curr;
void backtrack(vector<int>& candidates, int target,int strt){
    if(target==0) res.push_back(curr);
    if(target<0) return ;
    for(int i=strt;i<candidates.size();i++){
        curr.push_back(candidates[i]);
        backtrack(candidates,target-candidates[i],i);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        curr.clear();
        backtrack(candidates,target,0);
        return res;
    }
};