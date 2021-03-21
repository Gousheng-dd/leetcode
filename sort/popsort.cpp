#include<iostream>
#include<vector>

using namespace std;

void popsort(vector<int> &a){
    //冒泡排序 时间复杂度O(n^2) 空间复杂度O(1)
    int n=a.size();
    int flag;
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }
    return;
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    popsort(a);
    for(auto it=a.begin();it!=a.end();it++){
        cout<<*it<<'\t';
    }
    cout<<endl;
    return;
}

int main()
{
    test();
    return 0;
}