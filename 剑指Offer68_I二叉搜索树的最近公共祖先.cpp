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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||!p||!q){
            return NULL;
        }
        TreeNode* pNode=root;
        while(pNode){
            if(pNode->val<p->val&&pNode->val<q->val){
                pNode=pNode->right;
            }
            else if(pNode->val>p->val&&pNode->val>q->val){
                pNode=pNode->left;
            }
            else{
                return pNode;
            }
        }
        return NULL;
    }
};