/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (53.30%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    64.5K
 * Total Submissions: 120.6K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = [1,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中结点数在范围 [0, 10^4] 内
 * -1000 
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preOrder(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        TreeNode* root=preOrderDecode(data,idx);
        return root;
    }
private:
    void preOrder(TreeNode* root,string &res){
        if(root==NULL){
            res.append("$,");
            return;
        }
        res.append(to_string(root->val));
        res.append(",");
        preOrder(root->left,res);
        preOrder(root->right,res);
        return;
    }

    TreeNode* preOrderDecode(string &data,int &idx){
        if(data[idx]=='$'){
            idx+=2;
            return NULL;
        }
        int value=getValue(data,idx);
        TreeNode* root=new TreeNode(value);
        root->left=preOrderDecode(data,idx);
        root->right=preOrderDecode(data,idx);
        return root;
    }

    int getValue(string &data,int &idx){
        int res=0;
        bool negflag=false;
        if(data[idx]=='-'){
            negflag=true;
            idx++;
        }
        while(data[idx]!=','){
            res*=10;
            res+=(data[idx]-'0');
            idx++;
        }
        idx++;
        if(negflag){
            res=-res;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

