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
void solve(TreeNode* root,vector<int> temp, vector<vector<int>>& ans){
    if (root == NULL) return;
    temp.push_back(root->val); 
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(temp);
    } 
    solve(root->left, temp, ans); 
    solve(root->right, temp, ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<int> temp;
    vector<vector<int>> ans;
    solve(root, temp, ans); 
    vector<string> result;
        for (auto& path : ans) {
            string s = "";
            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1)
                    s += "->";
            }
            result.push_back(s);
        }

        return result;
    }
};