class Solution {
public:
  vector<vector<int>> result;
        vector<int> current;
void backtrack(int start,int k,int n ){
      if(n==0&&k==0) {
    result.push_back(current);
    return ;
      }
    if(k==0||n<0) return;

    for(int i=start;i<=9;i++){
        current.push_back(i);
        backtrack(i+1,k-1,n-i );
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n ) {
      
        backtrack(1,k,n );
        return result;
    }
};