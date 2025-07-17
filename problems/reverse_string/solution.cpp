class Solution {
public:
    void reverseString(vector<char>& s) {
        int strt=0;
        int end=s.size()-1;
        while(strt<end){
            swap(s[strt],s[end]);
            strt++;
            end--;
        }
    }
};