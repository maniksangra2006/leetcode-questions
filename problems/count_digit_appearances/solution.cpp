class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
         string s ="";
         for(int i=0;i<nums.size();i++){
               s+=to_string(nums[i]);
         }
         for(int i=0;i<s.size();i++){
            if(s[i]-'0'==digit) cnt++;
         }
         return cnt;
    }
};