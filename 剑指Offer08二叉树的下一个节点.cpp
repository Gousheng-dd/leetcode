/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *parent;
 * };
 */
class Solution {
public:
    TreeNode* GetNext(TreeNode* pNode) {
        if(pNode==NULL){
            return NULL;
        }
        if(pNode->right!=NULL){//有右子树则为右子树最左边的节点
            TreeNode* p=pNode->right;
            while (p->left!=NULL){
                p=p->left;
            }
            return p;
        }
        TreeNode* f=pNode->parent;
        if(f==NULL){
            return NULL;
        }
        if(f->left==pNode){//如果没有右子树且为父结点的左孩子则为父结点,可与第三种情况合并
            return f;
        }
        if(f->right==pNode){//如果没有右子树且为父结点的右孩子则向上找是其父结点的左子节点的结点
            TreeNode* p=pNode;
            while(f!=NULL&&f->left!=p){
                p=f;
                f=f->parent;
            }
            return p;
        }
        return NULL;
    }
};