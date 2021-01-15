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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()){
            return NULL;
        }
        stack<TreeNode*> s;
        TreeNode* root=new TreeNode(preorder[0]);
        TreeNode* cur=root;
        for(int i=1,j=0;i<inorder.size();i++){
            //有左子树时直到最左
            if(cur->val!=inorder[j]){
                cur->left= new TreeNode(preorder[i]);
                s.push(cur);
                cur=cur->left;
            }
            else{//没有左子树
                j++;
                while(!s.empty()&&s.top()->val==inorder[j]){//没有右子树则向上找祖先
                    cur=s.top();
                    s.pop();
                    j++;
                }
                //cur设为该右子树的根
                cur=cur->right=new TreeNode(preorder[i]);
            }
        }
        return root;
    }
};