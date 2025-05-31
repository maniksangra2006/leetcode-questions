class Solution {
public:
   vector<string> result;

   void generate (int n,string str,char lastChar){
    if(n==0){
        result.push_back(str);
        return;
    }
     generate(n-1,str+"1",'1');
    if(lastChar!='0'){
        generate(n-1,str+"0",'0');
    }
   }
    vector<string> validStrings(int n) {
        result.clear();
        generate(n,"",'1');
        return result;
    }
};