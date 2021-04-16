/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 *
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (56.27%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    46.7K
 * Total Submissions: 79.6K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 
 * 注意：本题与
 * 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * 相同
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 100] 内
 * 0 
 * 
 * 
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
    int minDiffInBST(TreeNode* root) {
        //二叉搜索树中与一个结点大小最接近的为其左子树最大值和右子树最小值
        //tips:其实只需要中序遍历即可，做麻烦了
        int minnum,maxnum;
        return findMinDiff(root,minnum,maxnum);
    }
private:
    int findMinDiff(TreeNode* root,int &minnum,int &maxnum){
        if(!root){
            minnum=maxnum=0;
            return 0x3f3f3f3f;
        }
        int lmax,lmin,rmax,rmin,mindiff=0x3f3f3f3f;
        if(root->left){
            mindiff=min(mindiff,findMinDiff(root->left,lmin,lmax));
            mindiff=min(mindiff,(root->val)-lmax);
        }
        else{
            lmax=INT_MIN;
            lmin=INT_MAX;
        }
        if(root->right){
            mindiff=min(mindiff,findMinDiff(root->right,rmin,rmax));
            mindiff=min(mindiff,rmin-(root->val));
        }
        else{
            rmin=INT_MAX;
            rmax=INT_MIN;
        }
        minnum=min(root->val,lmin);
        maxnum=max(root->val,rmax);
        return mindiff;
    }
};
// @lc code=end

