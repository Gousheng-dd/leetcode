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
    int kthLargest(TreeNode* root, int k) {
        if(!root||k<=0){
            return -1;
        }
        int res=-1;
        inorder(root,k,res);
        if(k<=0){
            return res;
        }
        return -1;
    }
private:
    void inorder(TreeNode* root,int &k,int &res){
        if(!root){
            return ;
        }
        if(root->right){
            inorder(root->right,k,res);
        }
        k--;
        if(k==0){
            res=root->val;
            return ;
        }
        if(root->left){
            inorder(root->left,k,res);
        }
        return;
    }
};