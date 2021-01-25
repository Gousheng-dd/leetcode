#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return {};
        }
        int wid=matrix.size(),len=matrix[0].size(),round=0;
        vector<int> res;
        while((round*2)+1<=min(len,wid)){
            for(int i=round;i<=len-round-1;i++){//从右向左一行
                res.push_back(matrix[round][i]);
            }
            if(round+1<=wid-round-1){
                for(int i=round+1;i<=wid-round-1;i++){//从上到下一列
                    res.push_back(matrix[i][len-round-1]);
                }
            }
            if(len-round-2>=round&&round+1<=wid-round-1){
                for(int i=len-round-2;i>=round;i--){//从左向右一行
                    res.push_back(matrix[wid-round-1][i]);
                }
            }
            if(wid-round-2>=round+1&&len-round-2>=round){
                for(int i=wid-round-2;i>=round+1;i--){//从下到上一列
                    res.push_back(matrix[i][round]);
                }
            }
            round++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    vector<vector<int> >inp={{1,2,3},{4,5,6},{7,8,9}};
    v=s.spiralOrder(inp);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}