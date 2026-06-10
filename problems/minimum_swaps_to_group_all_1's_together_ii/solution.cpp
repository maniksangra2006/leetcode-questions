class Solution {
public:

    int minSwaps(vector<int>& nums) {
        int n =nums.size();
        int ones=0;
        for(int i=0;i<n;i++){
        if(nums[i]==1) ones++;
        }
         vector<int> arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());
        int zeros=0; 
    
    for(int i=0;i<ones;i++){
      if(arr[i]==0) zeros++;
     
    }
     int ans=zeros;
   for (int r=ones;r<n+ones;r++) {
            if(arr[r-ones]==0)zeros--;  
            if(arr[r]==0)zeros++;       

            ans = min(ans, zeros);
        }
    
    return ans;
    }
};