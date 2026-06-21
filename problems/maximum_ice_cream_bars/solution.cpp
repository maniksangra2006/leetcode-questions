class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n =costs.size();
        long long ans=0;
        long long  cnt=0;
        for(int i=0;i<n;i++){
          ans+=costs[i];
          if(ans<=coins) cnt++;
        
        }
        return cnt;
    }
};