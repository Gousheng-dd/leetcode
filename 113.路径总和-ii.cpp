/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (61.40%)
 * Likes:    418
 * Dislikes: 0
 * Total Accepted:    112.3K
 * Total Submissions: 182.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
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
                if(tot==targetSum){
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
// @lc code=end

