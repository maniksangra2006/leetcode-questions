class Solution {
public:
   bool canCarry(int x,vector<int> &weights,int days){
        int sum=0;
         int cnt=1;
         for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>x){
                cnt++;
                sum=0;
            }
            sum+=weights[i];
         }
         return cnt<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int minDays=0;
        
                  while(low<=high){
                    int mid=(low+high)/2;

                    if(canCarry(  mid,weights,days)){
                      minDays=mid;
                         high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                  }
     return minDays;
    }

};