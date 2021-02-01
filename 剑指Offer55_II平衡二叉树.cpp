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
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int depth=0;
        return isBalanced(root,depth);
    }
private:
    bool isBalanced(TreeNode* root,int &depth){
        if(!root){
            depth=0;
            return true;
        }
        int left=0,right=0;
        if(isBalanced(root->left,left)&&isBalanced(root->right,right)){
            depth=(left>right)?(left+1):(right+1);
            if(left-right<=1&&left-right>=-1){
                return true;
            }
            return false;
        }
        return false;
    }
};