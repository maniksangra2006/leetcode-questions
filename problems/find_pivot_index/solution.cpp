class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 26,27,35,53,88,283,941,724,1299
        int sum=0;
        for(int &x:nums){
            sum+=x;
        }
        int cs=0;
        for(int i=0;i<nums.size();i++){
            int ls=cs;
            int rs=sum-cs-nums[i];
            if(ls==rs){
                return i;
            }
            cs+=nums[i];
        }
        return -1;
    }
};