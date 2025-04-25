class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(m!=n){
            return false;

        }
        for(int cnt=1;cnt<=m;cnt++){
            rotate(begin(s),begin(s)+1,end(s));
            if(s==goal)
            return true;
        }
        return false;
    }
};