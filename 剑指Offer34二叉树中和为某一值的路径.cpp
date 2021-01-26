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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return {};
        }
        stack<TreeNode* > q;
        vector<vector<int> > res;
        vector<TreeNode*> path;
        q.push(root);
        int tot=0;
        while(!q.empty()){
            TreeNode* tNode=q.top();
            q.pop();
            tot+=tNode->val;
            path.push_back(tNode);
            if(tNode->left==NULL&&tNode->right==NULL){
                if(tot==sum){
                    vector<int> pathres;
                    for(int i=0;i<path.size();i++){
                        pathres.push_back(path[i]->val);
                    }
                    res.push_back(pathres);
                    for(int i=path.size()-1;i>0;i--){
                        if(path[i-1]->right!=path[i]&&path[i-1]->right!=NULL){
                            tot-=path[i]->val;
                            path.pop_back();
                            break;
                        }
                        tot-=path[i]->val;
                        path.pop_back();
                    }
                }
                else{
                    for(int i=path.size()-1;i>0;i--){
                        if(path[i-1]->right!=path[i]&&path[i-1]->right!=NULL){
                            tot-=path[i]->val;
                            path.pop_back();
                            break;
                        }
                        tot-=path[i]->val;
                        path.pop_back();
                    }
                }
            }
            if(tNode->right){
                q.push(tNode->right);
            }
            if(tNode->left){
                q.push(tNode->left);
            }
        }
        return res;
    }
};