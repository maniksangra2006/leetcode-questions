class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n =words.size();
        int l=startIndex;
        int r =startIndex;
        int cnt=0;
        while(true){
            if(words[l]==target||words[r]==target) return cnt;
            l=(l-1+n)%n;
            r=(r+1)%n;
            cnt++;
        
        if(l==r){
            if(words[l]==target) return cnt;
            break;
        }
        }
        return -1;
    }
};