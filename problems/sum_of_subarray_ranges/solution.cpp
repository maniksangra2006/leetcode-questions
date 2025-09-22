class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n =nums.size();
        vector<long long>leftMax(n),rightMax(n),leftMin(n),rightMin(n);
        stack<int> st;
        //previous greater
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<=nums[i]) st.pop();
            leftMax[i]=st.empty()?i+1:i-st.top();
            st.push(i);
         }
         while(!st.empty()) st.pop();
        //next greater
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& nums[st.top()]<nums[i]) st.pop();
            rightMax[i]=st.empty()?n-i:st.top()-i;
            st.push(i);
        }
           while(!st.empty()) st.pop();
           //previous smaller
           for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]) st.pop();
            leftMin[i]=st.empty()? i+1 : i-st.top();
            st.push(i);
           }
            while(!st.empty()) st.pop();
            //previous greater
             for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]) st.pop();
            rightMin[i]=st.empty()? n-i: st.top()-i;
            st.push(i);
           }
           long long ans=0;
           for(int i=0;i<n;i++){
            long long maxPart=(long long)nums[i]*leftMax[i]*rightMax[i];
            long long minPart=(long long)nums[i]*leftMin[i]*rightMin[i];
            ans+=(maxPart-minPart);
           }
           return ans;
    }
};