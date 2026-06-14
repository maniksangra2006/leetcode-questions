class Solution {
public:
int possible(vector<int> &arr,int mid,int k ){
    int cnt=0;
    int cons=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=mid) cons++;
        else cons=0;
       if(cons==k) {
        cnt++;
       cons=0;
       }
    }
    return cnt;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int e =* max_element(bloomDay.begin(),bloomDay.end());
        int n =bloomDay.size();
        int mid =s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(possible(bloomDay,mid,k)>=m){
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