class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag=0;
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '&&flag) break;
            if(s[i]!=' '){
                flag=1;
                cnt++;
            }
        }
        return cnt;
    }
};