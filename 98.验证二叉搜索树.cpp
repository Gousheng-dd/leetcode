/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (33.67%)
 * Likes:    953
 * Dislikes: 0
 * Total Accepted:    232K
 * Total Submissions: 687.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        long long maxnum,minnum;
        return isVaildBSTCore(root,maxnum,minnum);
    }
private:
    bool isVaildBSTCore(TreeNode* root,long long &maxnum,long long &minnum){
        bool res=true,flag=false;
        long long lmax=LONG_MIN,lmin=LONG_MAX,rmax=LONG_MIN,rmin=LONG_MAX;
        if(root->left){
            res=res&&isVaildBSTCore(root->left,maxnum,minnum);
            lmax=maxnum;
            lmin=minnum;
            flag=true;
        }
        if(root->right){
            res=res&&isVaildBSTCore(root->right,maxnum,minnum);
            rmax=maxnum;
            rmin=minnum;
            flag=true;
        }
        if(!flag){
            maxnum=minnum=root->val;
            return true;
        }
        if(lmax<root->val&&rmin>root->val){
            res=res&&true;
        }
        else{
            res=false;
        }
        maxnum=max(rmax,(long long)root->val);
        minnum=min(lmin,(long long)root->val);
        return res;
    }
};
// @lc code=end

