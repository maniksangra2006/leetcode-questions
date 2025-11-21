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
TreeNode* minVal(TreeNode* root) {
    TreeNode* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 left child
        if(root->left!=NULL && root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        //1 right child
        if(root->right!=NULL && root->left==NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
         int mini=minVal(root->right)->val;
         root->val=mini;
         root->right=deleteNode(root->right,mini);
         return root;
        }
        
        return root;
    }
};