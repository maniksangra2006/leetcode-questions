class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int  fathest=0;
        int urr=0;
        for(int i=0;i<nums.size()-1;i++){
            fathest=max(fathest,i+nums[i]);
        if(urr==i){
            jumps++;
            urr=fathest;
        }
        }
        return jumps;
    }
};