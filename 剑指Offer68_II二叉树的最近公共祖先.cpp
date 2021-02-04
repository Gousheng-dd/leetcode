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
        vector<TreeNode* >path1,path2;
        if(!getPath(root,p,path1)||!getPath(root,q,path2)){
            return NULL;
        }
        TreeNode* res=root;
        for(int i=0,j=0;i<path1.size()&&j<path2.size();i++,j++){
            if(path1[i]!=path2[j]){
                break;
            }
            res=path1[i];
        }
        return res;
    }
private:
    bool getPath(TreeNode* root,TreeNode* dst,vector<TreeNode*> &path){
        if(root==dst){
            path.push_back(root);
            return true;
        }
        if(!root){
            return false;
        }
        path.push_back(root);
        bool found=getPath(root->left,dst,path)||getPath(root->right,dst,path);
        if(!found){
            path.pop_back();
        }
        return found;
    }
};