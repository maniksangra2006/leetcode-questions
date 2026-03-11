class Solution {
public:
vector<string> split(string s){
    vector<string> res;
    string ans="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            res.push_back(ans);
            ans="";
        }
        else {
            ans+=s[i];
        }
    }
        res.push_back(ans);
    
    return res;
}
    int compareVersion(string version1, string version2) {
        vector<string> v1=split(version1);
        vector<string> v2=split(version2);
        int n =max(v1.size(),v2.size());
        for(int i=0;i<n;i++){
            int n1=(i<v1.size())? stoi(v1[i]) :0;
            int n2=(i<v2.size())? stoi(v2[i]) :0;
            if(n1>n2) return 1;
            if(n1<n2) return -1;
        }
        return 0;
    }
};