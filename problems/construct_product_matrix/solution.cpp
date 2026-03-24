class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod=12345;
        int n =grid.size();
        int m =grid[0].size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]% mod);
            }
        }
        int N=arr.size();
        vector<int> pre(N,1);
        for(int i=1;i<N;i++){
            pre[i]=(pre[i-1]*arr[i-1])% mod;
        }
        vector<int> suff(N,1);
        for(int i=N-2;i>=0;i--){
          suff[i]=(suff[i+1]*arr[i+1]) % mod; 
        }
        vector<int> res(N);
        for(int i=0;i<N;i++){
            res[i]=(pre[i]*suff[i])% mod;
        }
        vector<vector<int>> result(n,vector<int>(m));
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=res[idx++];
            }
        }
        return result;
    }
};