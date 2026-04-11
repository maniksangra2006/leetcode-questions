class Solution {
public:
    bool isPrime(int n ){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ops=0;
        for(int i=0;i<n;i++){
             int val=nums[i];
            if(i%2==0){
                while(!isPrime(val)){
                    val++;
                    ops++;
                }
            }
            else {
                
                while(isPrime(val)){
                    val++;
                    ops++;
                }
            }
        }
        return ops;
    }
};