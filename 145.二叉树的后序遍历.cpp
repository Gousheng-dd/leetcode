/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (74.23%)
 * Likes:    538
 * Dislikes: 0
 * Total Accepted:    196.4K
 * Total Submissions: 264.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int > res;
        stack<TreeNode*> stk;
        TreeNode* pNode=root,*preNode=NULL;
        while(pNode||!stk.empty()){
            while(pNode){
                stk.push(pNode);
                pNode=pNode->left;
            }
            pNode=stk.top();
            if(pNode->right==NULL||pNode->right==preNode){
                //表示右子树遍历完
                res.push_back(pNode->val);
                stk.pop();
                preNode=pNode;
                pNode=NULL;
            }
            else{
                pNode=pNode->right;
            }
        }
        return res;
    }
};
// @lc code=end

