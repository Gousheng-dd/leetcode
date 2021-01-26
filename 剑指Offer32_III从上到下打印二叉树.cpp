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
        vector<vector<int> >res;
        vector<int> depres;
        queue<pair<TreeNode* , int> > q;
        int depth=0;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode* , int> p=q.front();
            q.pop();
            if(p.second==depth){
                depres.push_back(p.first->val);
            }
            else{
                if(depth%2){
                    reverse(depres.begin(),depres.end());
                }
                res.push_back(depres);
                depres.clear();
                depres.push_back(p.first->val);
                depth++;
            }
            if(p.first->left){
                q.push(make_pair(p.first->left,p.second+1));
            }
            if(p.first->right){
                q.push(make_pair(p.first->right,p.second+1));
            }
        }
        if(depth%2){
            reverse(depres.begin(),depres.end());
        }
        res.push_back(depres);
        return res;
    }
};