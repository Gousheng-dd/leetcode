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

//查找结点
TreeNode* searchNode(TreeNode* root,int value){
    if(!root){
        return NULL;
    }
    if(value>root->val){
        return searchNode(root->leftchild,value);
    }
    return searchNode(root->rightchild,value);
}

//删除结点
bool removeNode(TreeNode* &root,int value){
    if(!root){
        return false;
    }
    if(value==root->val){
        if(root->leftchild==NULL&&root->rightchild==NULL){
            delete root;
            root=NULL;
        }
        else if(root->leftchild&&root->rightchild==NULL){
            TreeNode* pNode=root;
            root=root->leftchild;
            delete root;
        }
        else if(root->rightchild&&root->leftchild==NULL){
            TreeNode* pNode=root;
            root=root->rightchild;
            delete root;
        }
        else{
            //左右孩子都在则取左子树最右边结点和其交换后删除该结点
            TreeNode* pNode=root->leftchild;
            while(pNode->rightchild){
                pNode=pNode->rightchild;
            }
            root->val=pNode->val;
            pNode->val=value;
            removeNode(root->leftchild,value);
        }
    }
    else if(value<root->val){
        if(!removeNode(root->leftchild,value)){
            return false;
        }
    }
    else{
        if(!removeNode(root->rightchild,value)){
            return false;
        }
    }
    updateHeight(root);
    if(getBalanceFactor(root)==2){
        if(getBalanceFactor(root->leftchild)>=0){
            //LL
            rightshift(root);
        }
        else if(getBalanceFactor(root->leftchild)==-1){
            //LR
            leftshift(root->leftchild);
            rightshift(root);
        }
    }
    else if(getBalanceFactor(root)==-2){
        if(getBalanceFactor(root->rightchild)<=0){
            //RR
            leftshift(root);
        }
        else if(getBalanceFactor(root->rightchild)==1){
            //RL
            rightshift(root->rightchild);
            leftshift(root);
        }
    }
    return true;
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
    removeNode(root,root->val);
    printf("%d\n",root->val);
    delete []data;
    return 0;
}