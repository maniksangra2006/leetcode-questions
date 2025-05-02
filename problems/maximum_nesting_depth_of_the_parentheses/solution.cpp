class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int max_depth=0;
        for(char c: s){
            if(c=='('){
                cnt++;
                if(max_depth<cnt)
                    max_depth=cnt;
            }
            else if (c==')'){
                cnt--;
            }
            
        }
        return max_depth;
    }
};