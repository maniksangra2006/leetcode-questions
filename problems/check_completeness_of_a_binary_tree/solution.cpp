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
 int countnodes(TreeNode* root){
      if(root==NULL) return 0;
      int ans =1+countnodes(root->left)+countnodes(root->right);
      return ans;
  }
    bool isCBT(TreeNode* root,int idx,int cnt){
       if(root==NULL) return true;
       if(cnt<=idx) return false;
       else{
           bool left=isCBT(root->left,2*idx+1,cnt);
           bool right=isCBT(root->right,2*idx+2,cnt); 
           return(left&&right);
       }
  }
    bool isCompleteTree(TreeNode* root) {
        int cnt=countnodes(root);
        return isCBT(root,0,cnt);
    }
};