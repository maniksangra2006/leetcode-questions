class Solution {
public:
vector<vector<int>> res;
vector<int> curr;
void backtrack(vector<int>& candidates, int target,int strt){
    if(target==0){
 res.push_back(curr);
 return;
    }
   
    for(int i=strt;i<candidates.size();i++){
           if(i>strt && candidates[i]==candidates[i-1]) continue;
    if(candidates[i]>target) break;
        curr.push_back(candidates[i]);
        backtrack(candidates,target-candidates[i],i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                sort(candidates.begin(),candidates.end());

        res.clear();
        curr.clear();
        backtrack(candidates,target,0);
        return res;
    }
};