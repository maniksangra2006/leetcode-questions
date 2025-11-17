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
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStart, int inEnd, 
                    unordered_map<int,int> &indexMap) {
        if (preIndex >= preorder.size() || inStart > inEnd)
            return nullptr;
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = indexMap[element];
        root->left = solve(preorder, inorder, preIndex, inStart, pos - 1, indexMap);
        root->right = solve(preorder, inorder, preIndex, pos + 1, inEnd, indexMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        int preIndex = 0;
        return solve(preorder, inorder, preIndex, 0, inorder.size() - 1, indexMap);
    }
};
