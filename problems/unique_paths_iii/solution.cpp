class Solution {
public:
  
    int dfs(vector<vector<int>>& grid,int i,int j, int remain){
        int m=grid.size();
        int n =grid[0].size();
    if(i<0||j<0||i>=m||j>=n||grid[i][j]==-1) return 0;
    if(grid[i][j]==2)
    return(remain==0)? 1:0;
    int temp=grid[i][j];
    grid[i][j]=-1;
    int paths=dfs(grid,i+1,j,remain-1)+
              dfs(grid,i-1,j,remain-1)+
              dfs(grid,i,j+1,remain-1)+
              dfs(grid,i,j-1,remain-1);
              grid[i][j]=temp;
              return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n =grid[0].size();
        int strt_i;
        int strt_j;
        int empty=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if(grid[i][j]!=-1) empty++;
             if(grid[i][j]==1){
                strt_i=i;
                strt_j=j;
             }
            }
        }
        return dfs(grid,strt_i,strt_j,empty-1);
    }
};