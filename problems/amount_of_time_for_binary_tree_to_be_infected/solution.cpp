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

    // Build parent map and return target node
    TreeNode* buildParentMap(TreeNode* root, int target,
        unordered_map<TreeNode*, TreeNode*>& parent) 
    {
        queue<TreeNode*> q;
        q.push(root);

        parent[root] = NULL;
        TreeNode* targetNode = NULL;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == target)
                targetNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return targetNode;
    }

    // BFS to burn tree starting at targetNode
    int burn(TreeNode* targetNode, 
             unordered_map<TreeNode*, TreeNode*>& parent)
    {
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                // left child
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                    burned = true;
                }

                // right child
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                    burned = true;
                }

                // parent
                TreeNode* p = parent[node];
                if (p && !visited.count(p)) {
                    visited.insert(p);
                    q.push(p);
                    burned = true;
                }
            }

            if (burned) time++;
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* targetNode = buildParentMap(root, start, parent);

        return burn(targetNode, parent);
    }
};
