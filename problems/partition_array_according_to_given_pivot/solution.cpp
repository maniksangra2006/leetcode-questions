class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n =nums.size();
        int s=0;
        vector<int>ans(n,pivot);
        int e=n-1;
        for(int i=0,j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                ans[s++]=nums[i];
            }
            if(nums[j]>pivot){
                ans[e--]=nums[j];
            }
        }
        return ans;
    }
};