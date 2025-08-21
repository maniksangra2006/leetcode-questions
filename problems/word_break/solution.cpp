 class Solution {
public:
    int n;
    unordered_set<string> st;
    int t[301];

    bool solve(int idx, string &s) {
        if (idx == n) return true;           
        if (t[idx] != -1) return t[idx];     

        for (int l = 1; l <= n - idx; l++) {   
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(t, -1, sizeof(t));
        st.clear();

        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
