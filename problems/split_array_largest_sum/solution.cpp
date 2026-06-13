class Solution {
public:
bool ispossible(vector<int> & nums,int n,int m,int mid){
    int cnt=1;
    int pagesum=0;
    for(int i=0;i<n;i++){
        if(pagesum+nums[i]<=mid){
            pagesum+=nums[i];
        }
        else {
            cnt++;
            if(cnt>m||nums[i]>mid){
                return false;
            }  
            pagesum=nums[i];
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int sum=0;
        int n =nums.size();
        for(int i=0;i<n;i++){
         sum+=nums[i];
        }
        int e =sum;
        int ans=-1;
        int mid =s+(e-s)/2;
        while(s<=e){
            if (ispossible(nums,n,k,mid)){
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