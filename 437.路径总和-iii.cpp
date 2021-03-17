/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (56.59%)
 * Likes:    777
 * Dislikes: 0
 * Total Accepted:    69K
 * Total Submissions: 122K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
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
    //后序遍历+前缀和+hash
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        int res=0,nowsum=0;
        unordered_map<int,int> ump;
        stack<TreeNode*> s;
        TreeNode* pNode=root,*preNode=NULL;
        while(pNode||!s.empty()){
            while(pNode){
                nowsum+=pNode->val;
                if(ump.find(nowsum)!=ump.end()){
                    ump[nowsum]++;
                }
                else{
                    ump[nowsum]=1;
                }
                s.push(pNode);
                pNode=pNode->left;
            }
            pNode=s.top();
            if(pNode->right==NULL||pNode->right==preNode){
                if(ump.find(nowsum-sum)!=ump.end()){
                    if(sum==0){
                        res+=ump[nowsum-sum]-1;
                    }
                    else{
                        res+=ump[nowsum-sum];
                    }
                }
                if(nowsum==sum){
                    res++;
                }
                ump[nowsum]--;
                nowsum-=pNode->val;
                preNode=pNode;
                s.pop();
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

