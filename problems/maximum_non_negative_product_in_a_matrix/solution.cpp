class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long >> mindp(n,vector<long long>(m));
        vector<vector<long long>> maxdp(n,vector<long long>(m));
        const long long MOD=1e9+7;
        maxdp[0][0]=mindp[0][0]=grid[0][0];
        for(int j=1;j<m;j++){
            maxdp[0][j]=maxdp[0][j-1]*grid[0][j];
             mindp[0][j]=maxdp[0][j];  
        }
        for(int i=1;i<n;i++){
           maxdp[i][0]=maxdp[i-1][0]*grid[i][0];
           mindp[i][0]=maxdp[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
               long long val=grid[i][j];
               long long a=maxdp[i-1][j]*val;
               long long b=mindp[i-1][j]*val;
               long long c=maxdp[i][j-1]*val;
               long long d=mindp[i][j-1]*val;
               maxdp[i][j]=max({a,b,c,d});
               mindp[i][j]=min({a,b,c,d});
            }
        }
        long long ans=maxdp[n-1][m-1];
        if(ans<0)return -1;
        return ans%MOD;
    }
};