/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (65.01%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    95.2K
 * Total Submissions: 146.5K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        int nownum=1,nextnum=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            TreeNode* pNode=q.front();
            if(pNode->left){
                q.push(pNode->left);
                nextnum++;
            }
            if(pNode->right){
                q.push(pNode->right);
                nextnum++;
            }
            q.pop();
            nownum--;
            if(!nownum){
                nownum=nextnum;
                nextnum=0;
                res.push_back(pNode->val);
            }
        }
        return res;
    }
};
// @lc code=end

