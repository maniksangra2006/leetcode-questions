class Solution {
public:
    bool isPrime(int n ){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
          int temp=n;
        int x=0;
     
        while(n!=0){
           int rem =n%10;
            x=x*10+rem;
            n=n/10;
        }
        long long sum=0;
        int start=min(temp,x);
        int end=max(temp,x);
         for(int i=start;i<=end;i++){
             if(isPrime(i)) sum+=i;
         }
        return sum;
    }
};