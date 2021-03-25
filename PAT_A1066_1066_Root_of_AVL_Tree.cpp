#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode* leftchild;
    TreeNode* rightchild;
    TreeNode(int v):val(v){
        this->height=-1;
        this->leftchild=this->rightchild=NULL;
    }
};

//右旋
void rightshift(TreeNode* &root){
    TreeNode* newroot=root->leftchild;
    root->leftchild=root->leftchild->rightchild;
    newroot->rightchild=root;
    root=newroot;
    return;
}

//左旋
void leftshift(TreeNode* &root){
    TreeNode* newroot=root->rightchild;
    root->rightchild=root->rightchild->leftchild;
    newroot->leftchild=root;
    root=newroot;
    return;
}

//更新树高
int updateHeight(TreeNode* root){
    if(!root){
        return 0;
    }
    root->height=max(updateHeight(root->leftchild),updateHeight(root->rightchild))+1;
    return root->height;
}

//获得树高
int getHeight(TreeNode* root){
    if(!root){
        return 0;
    }
    return root->height;
}

//计算平衡因子
int getBalanceFactor(TreeNode* root){
    if(!root){
        return 0;
    }
    return getHeight(root->leftchild)-getHeight(root->rightchild);
}

//插入结点
void insertNode(TreeNode* &root,int value){
    if(!root){
        root=new TreeNode(value);
        return ;
    }
    if(value<root->val){
        insertNode(root->leftchild,value);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->leftchild)==1){
                //LL
                rightshift(root);
            }
            else if(getBalanceFactor(root->leftchild)==-1){
                //LR
                leftshift(root->leftchild);
                rightshift(root);
            }
        }
    }
    else{
        insertNode(root->rightchild,value);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->rightchild)==-1){
                //RR
                leftshift(root);
            }
            else if(getBalanceFactor(root->rightchild)==1){
                //RL
                rightshift(root->rightchild);
                leftshift(root);
            }
        }
    }
    return;
}

//建AVL树
TreeNode* createAVLTree(int* data,int n){
    if(!data){
        return NULL;
    }
    TreeNode* root=NULL;
    for(int i=0;i<n;i++){
        insertNode(root,data[i]);
    }
    return root;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *data=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    TreeNode* root=createAVLTree(data,n);
    printf("%d\n",root->val);
    delete []data;
    return 0;
}