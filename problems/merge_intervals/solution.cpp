class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &  intervals) {
         sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        int previous_l = intervals[0][0];
        int previous_r = intervals[0][1];

        for(auto interval:intervals){
            int l = interval[0],r = interval[1];
            if(l <= previous_r && r >= previous_r){ // merge
                previous_r = r;
            }
            else if(l > previous_r && r > previous_r){ // do not merge
                ans.push_back({previous_l,previous_r});
                previous_l = l;
                previous_r = r;
            }
        }
        ans.push_back({previous_l,previous_r});

        return ans;
    }
};