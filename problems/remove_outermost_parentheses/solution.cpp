class Solution {
public:
    string removeOuterParentheses(string s) {
         int cnt=0;
         int i=0;
         string ans="";
         while(i<s.size()){
            if(s[i]=='('){
                if(cnt>0){
                    ans+=s[i];
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt>0){
                    ans+=s[i];
                }
            }
            i++;
         }
         return ans;
    }
};