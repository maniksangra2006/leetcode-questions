class Solution {
public:
bool ispossible(vector<int> & nums,int n,int m,int mid){
    int cnt=1;
    int lastpos=nums[0];
    for(int i=0;i<n;i++){
        if(nums[i]-lastpos>=mid){
           cnt++;
           if(cnt==m) return true;
           lastpos=nums[i];
        }
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        int s=0;
       sort(position.begin(),position.end());
       int e= *max_element(position.begin(),position.end()); 
        int n =position.size();
        int ans=-1;
        int mid =s+(e-s)/2;
        while(s<=e){
            if (ispossible(position,n,m,mid)){
                ans=mid;
                s=mid+1;
            }
            else {
               e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};