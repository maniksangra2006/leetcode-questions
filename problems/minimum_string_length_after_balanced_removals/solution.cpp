class Solution {
public:
    int minLengthAfterRemovals(string s) {
        string str=s;
        int cnt1=0;
        int cnt2=0;
        for (char c: str){
        if(c=='a') cnt1++;
        else cnt2++;
        }
        return abs(cnt1-cnt2);
    }
};