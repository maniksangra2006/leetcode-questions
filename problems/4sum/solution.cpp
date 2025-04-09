class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<nums.size();j++)
            {
                if(j!= i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }
                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    if(nums[l] == nums[l-1] && l!= j+1)
                    {
                        l++;
                    }
                    else if(r != nums.size()-1 && nums[r] == nums[r+1])
                    {
                        r--;
                    }
                    else if((long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r] == (long long)target)
                    {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                    else if((long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r] < (long long)target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return res;  
    }
};