class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         int n =grid.size();
         int tot=n*n;
         vector<int>freq(tot+1,0);
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
         }
         int rep=-1;
         int mis=-1;
         for(int i=0;i<=tot;i++){
            if(freq[i]==2) rep=i;
            else if (freq[i]==0)   mis=i;
            
         }
    return {rep,mis};
    }
};