class Solution {
public:
    bool isValid(string word) {
  
        int n= word.size();
        if(n<3) return false;
          int vowel=0;
          int cons=0;
          string list="aeiouAEIOU";
          for(char c:word){
          
         if(isalpha(c)){
             if(list.find(c)!=string::npos){
                vowel++;
             }else{
                cons++;
             }
         }else if (!isdigit(c)){
            return false;
         }
          }
      return vowel>=1 && cons>=1;
    }
};