class Solution {
public:
    int minOperations(int n) {
        int ops=0;
        int tar=n;
        for(int i=0;i<n/2;i++){
            int curr=(2*i)+1;
            ops+=(tar-curr);
        }
        return ops;
    }
};