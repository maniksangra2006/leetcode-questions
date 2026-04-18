class Solution {
public:
    int mirrorDistance(int n) {
        int x;
        int a=n;
        while(a>0){
        int ans=a%10;
        x=x*10+ans;
        a=a/10;
        }
        return abs(x-n);
    }
};