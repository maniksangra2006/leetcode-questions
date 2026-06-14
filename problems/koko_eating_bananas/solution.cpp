class Solution {
public:
bool possible(vector<int> &piles,int mid,int h){
    long long cnt=0;
    for(int i=0;i<piles.size();i++){
        int x =piles[i];
        cnt+=x/mid;
        if(x%mid!=0) cnt++;
    }
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int mid =s+(e-s)/2;
        int ans=-1;
        while(s<=e){
           if (possible(piles,mid,h)){
                 ans=mid;
                 e=mid-1;
        }
         else {
            s=mid+1;
         }
         mid=s+(e-s)/2;
        }
        return ans;
    }
};