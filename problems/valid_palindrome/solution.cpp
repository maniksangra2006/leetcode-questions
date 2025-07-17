class Solution {
public:
    bool isPalindrome(string s) {
        int strt=0;
        int end=s.size()-1;
        while(strt<end){
        while (strt < end && !isalnum(s[strt])) strt++;
        while (strt < end && !isalnum(s[end])) end--;

            if (tolower(s[strt]) != tolower(s[end])) {
            return false;
        }
        strt++;
        end--;
        }
        return true;
    }
};