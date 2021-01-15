/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (68.81%)
 * Likes:    826
 * Dislikes: 0
 * Total Accepted:    143.7K
 * Total Submissions: 208.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

// @lc code=start
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size());
    }
private:
    int index=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end){
        if(start==end){
            return NULL;
        }
        TreeNode* root=new TreeNode();
        root->val=preorder[index];
        for(int i=start;i<end;i++){
            if(inorder[i]==preorder[index]){
                index++;
                root->left=build(preorder,inorder,start,i);
                root->right=build(preorder,inorder,i+1,end);
                break;
            }
        }
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {//真的切分浪费
//         if(preorder.size()==0){
//             return NULL;
//         }
//         TreeNode* root=new TreeNode();
//         root->val=preorder[0];
//         vector<int>::iterator in_root;
//         in_root=find(inorder.begin(),inorder.end(),preorder[0]);
//         int leftlen=in_root-inorder.begin();
//         int rightlen=inorder.end()-in_root-1;
//         vector<int> preleft(preorder.begin()+1,preorder.begin()+leftlen+1);
//         vector<int> preright(preorder.end()-rightlen,preorder.end());
//         vector<int> inleft(inorder.begin(),in_root);
//         vector<int> inright(in_root+1,inorder.end());
//         root->left=buildTree(preleft,inleft);
//         root->right=buildTree(preright,inright);
//         return root;
//     }
// };
// @lc code=end

