/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (64.18%)
 * Likes:    800
 * Dislikes: 0
 * Total Accepted:    263.6K
 * Total Submissions: 410.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层序遍历结果：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        int nowdepth=0;
        queue<pair<TreeNode*,int> > q;
        pair<TreeNode*,int> p;
        vector<vector<int> > res;
        vector<int> dep;
        q.push(make_pair(root,0));
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(p.second!=nowdepth){
                res.push_back(dep);
                dep.clear();
                nowdepth=p.second;
            }
            dep.push_back(p.first->val);
            if(p.first->left){
                q.push(make_pair(p.first->left,p.second+1));
            }
            if(p.first->right){
                q.push(make_pair(p.first->right,p.second+1));
            }
        }
        res.push_back(dep);
        return res;
    }
};
// @lc code=end

