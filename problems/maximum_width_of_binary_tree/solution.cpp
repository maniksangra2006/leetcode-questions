/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ 
 class Solution {
public:
    long long ans = 0;
    vector<long long> first;  // leftmost index per depth

    void dfs(TreeNode* root, long long idx, int depth) {
        if (!root) return;

        // First time reaching this level → record starting index
        if (first.size() == depth)
            first.push_back(idx);

        long long normalized = idx - first[depth];   // prevent overflow

        ans = max(ans, normalized + 1);

        // Use normalized index for children to keep numbers small
        dfs(root->left, 2 * normalized + 1, depth + 1);
        dfs(root->right, 2 * normalized + 2, depth + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};
