class Solution {
public:
void solve(string digits,string output,vector<string>& ans,int idx,string mapping[]){
    if(idx>=digits.size()) {
        ans.push_back(output);
        return;
    }
    int num=digits[idx]-'0';
    string val=mapping[num];
    for(int i=0;i<val.size();i++){
        output.push_back(val[i]);
        solve(digits,output,ans,idx+1,mapping);
        output.pop_back();
        
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        int idx=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,ans,idx,mapping);
        return ans;
    }
};