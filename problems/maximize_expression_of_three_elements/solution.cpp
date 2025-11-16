class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
     int max1=INT_MIN;
        int max2=INT_MIN;
        int minval=INT_MAX;
        for(int x:nums){
            minval=min(minval,x);

            if(x>max1){
                max2=max1;
                max1=x;
            }
            else if (x>max2){
                max2=x;
            }
        }
        return max1+max2-minval;
    }
};