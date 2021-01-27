/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root){
            return NULL;
        }
        Node* lastNode=NULL;
        Tree2List(root,&lastNode);
        Node* pNode=lastNode;
        while(pNode&&pNode->left){
            pNode=pNode->left;
        }
        pNode->left=lastNode;
        lastNode->right=pNode;
        return pNode;
    }
private:
    void Tree2List(Node* root,Node** lastNode){
        if(root->left){
            Tree2List(root->left,lastNode);
        }
        root->left=*lastNode;
        if(*lastNode){
            (*lastNode)->right=root;
        }
        *lastNode=root;
        if(root->right){
            Tree2List(root->right,lastNode);
        }
        return;
    }
};