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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL){
            return false;
        }
        if(hasSubStructure(A,B)){
            return true;
        }
        return isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
private:
    bool hasSubStructure(TreeNode* A,TreeNode* B){
        if(B==NULL){
            return true;
        }
        if(A==NULL){
            return false;
        }
        return (A->val==B->val)&&hasSubStructure(A->left,B->left)&&hasSubStructure(A->right,B->right);
    }
};