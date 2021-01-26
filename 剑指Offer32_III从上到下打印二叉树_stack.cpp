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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode* >levels[2];
        int current=0,next=1;
        levels[current].push(root);
        vector<vector<int> > res;
        vector<int> depres;
        while((!levels[0].empty())||(!levels[1].empty())){
            TreeNode* tNode=levels[current].top();
            depres.push_back(tNode->val);
            levels[current].pop();
            if(current){
                if(tNode->right){
                    levels[next].push(tNode->right);
                }
                if(tNode->left){
                    levels[next].push(tNode->left);
                }
            }
            else{
                if(tNode->left){
                    levels[next].push(tNode->left);
                }
                if(tNode->right){
                    levels[next].push(tNode->right);
                }
            }
            if(levels[current].empty()){
                res.push_back(depres);
                depres.clear();
                current=1-current;
                next=1-next;
            }
        }
        return res;
    }
};