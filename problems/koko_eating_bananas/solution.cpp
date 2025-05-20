class Solution {
public: 
bool canEatAll(vector<int>& piles ,int mid,int h){
      long long actualHours = 0;
    for (int i=0;i<piles.size();i++) {
    int x = piles[i]; 
        actualHours += x/mid;  
        if(x%mid!=0){
            actualHours++;
        }
    }
    return actualHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(canEatAll(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
          else{
                    low=mid+1;
                }
        }
        return ans;
    }
};