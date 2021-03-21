#include<iostream>
#include<vector>

using namespace std;

void selectsort(vector<int> &a){
    //选择排序，时间复杂度O(n^2),空间复杂度O(1)
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int minnum=a[i],idx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<minnum){
                minnum=a[j];
                idx=j;
            }
        }
        swap(a[i],a[idx]);
    }
    return;
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    selectsort(a);
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