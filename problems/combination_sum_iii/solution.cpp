class Solution {
public:
vector<vector<int>> res;
vector<int> curr;
    void backtrack(int strt,int k,int n){
        if(n==0 &&k==0) {
            res.push_back(curr);
            return;
        }
        if(k==0||n<0 ) return;
        for(int i=strt;i<=9;i++){
            curr.push_back(i);
            backtrack(i+1,k-1,n-i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1,k,n);
        return res;
    }
};