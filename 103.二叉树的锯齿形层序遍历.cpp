/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.11%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    127.3K
 * Total Submissions: 222.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层序遍历如下：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode*> s[2];
        int current=1;
        vector<vector<int> > res;
        vector<int> depres;
        s[current].push(root);
        while(!s[current].empty()){
            TreeNode* pNode=s[current].top();
            if(current){
                if(pNode->left){
                    s[1-current].push(pNode->left);
                }
                if(pNode->right){
                    s[1-current].push(pNode->right);
                }
            }
            else{
                if(pNode->right){
                    s[1-current].push(pNode->right);
                }
                if(pNode->left){
                    s[1-current].push(pNode->left);
                }
            }
            s[current].pop();
            depres.push_back(pNode->val);
            if(s[current].empty()){
                res.push_back(depres);
                depres.clear();
                current=1-current;
            }
        }
        return res;
    }
};
// @lc code=end

