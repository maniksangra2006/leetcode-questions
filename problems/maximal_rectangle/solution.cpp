class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            // Update heights
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j] += 1;
                else height[j] = 0;
            }
            // Compute largest rectangle for current histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
private:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int maxA = 0;
        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : h[i];
            while (!st.empty() && curr < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
};
