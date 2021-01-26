class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0){
            return true;
        }
        return verifyPostorderCore(postorder,0,postorder.size()-1);
    }
private:
    bool verifyPostorderCore(vector<int>& postorder,int start,int root)
    {
        int leftend;
        for(leftend=start;leftend<root;leftend++){
            if(postorder[leftend]>postorder[root]){
                break;
            }
        }
        for(int i=leftend;i<root;i++){
            if(postorder[i]<postorder[root]){
                return false;
            }
        }
        bool res;
        if(leftend==start){
            res=true;
        }
        else{
            res=verifyPostorderCore(postorder,start,leftend-1);
        }
        if(postorder[leftend]>postorder[root]){
            res=res&&verifyPostorderCore(postorder,leftend,root-1);
        }
        return res;
    }
};