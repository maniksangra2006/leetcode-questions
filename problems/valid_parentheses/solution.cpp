 class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Changed from stack<int> to stack<char>
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false;
                
                char ch = st.top();
                st.pop();
                
                // Fixed the logic - need to continue if match, return false if no match
                if((s[i] == ')' && ch == '(') || 
                   (s[i] == ']' && ch == '[') || 
                   (s[i] == '}' && ch == '{')) {
                    continue;  // Valid pair found, continue to next character
                }
                else {
                    return false;  // Invalid pair
                }
            }
        }
        return st.empty();
    }
};