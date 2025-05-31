class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastSeen;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(lastSeen.find(nums[i])!=lastSeen.end()){
                if(abs(i-lastSeen[nums[i]])<=k){
                    return true;
                }
            }
            lastSeen[nums[i]]=i;
        }
        return false;
    }
};