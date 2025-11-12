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
 */ class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes; // {hd → {lvl → list of values}}
        queue<pair<TreeNode*, pair<int,int>>> q; // {node, {hd, lvl}}
         vector<vector<int> >ans; // final output

        if(root == NULL) return ans;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if(frontNode->left){
                q.push({frontNode->left, {hd - 1, lvl + 1}});
            }
            if(frontNode->right){
                q.push({frontNode->right, {hd + 1, lvl + 1}});
            }
        }
  for (auto &i : nodes) {
            vector<int> col;
            for (auto &j : i.second) {
                vector<int> temp = j.second;
                sort(temp.begin(), temp.end()); // sort same-level nodes
                col.insert(col.end(), temp.begin(), temp.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
