class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++) {
            int val=0;
            int num=nums[i]; 
            while(num>0) {
                val+=num%10;   
                num/=10;       
            }
            ans=min(ans,val);
        }
        return ans; 
    }
};