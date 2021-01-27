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
// Codec codec;
// codec.deserialize(codec.serialize(root));