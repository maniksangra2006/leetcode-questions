class Solution {
public:
    int last(vector<int> &nums,int target){
        int s=0;
        int n =nums.size();
        int e=n-1;
        int ans=-1;;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
                 
            }
            else if (target>nums[mid]){
              s=mid+1;
            }
            else {
             e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    int first(vector<int> &nums,int target){
        int s=0;
        int n =nums.size();
        int e=n-1;
        int ans=-1;;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
                 
            }
            else if (target>nums[mid]){
              s=mid+1;
            }
            else {
             e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=first(nums,target);
        int th=last(nums,target);
        vector<int> ans;
        ans.push_back(st);
        ans.push_back(th);
        return ans;
    }
};