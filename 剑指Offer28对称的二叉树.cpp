/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return symmetric(root,root);
    }
private:
    bool symmetric(TreeNode* roota,TreeNode* rootb) {
        if(roota==NULL&&rootb==NULL){
            return true;
        }
        if(roota==NULL||rootb==NULL){
            return false;
        }
        return (roota->val==rootb->val)&&symmetric(roota->left,rootb->right)&&symmetric(roota->right,rootb->left);
    }
};