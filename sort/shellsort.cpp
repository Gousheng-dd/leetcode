#include<iostream>
#include<vector>

using namespace std;

void shellsortCore(vector<int> &a,vector<int> &dks){
    int n=a.size(),t=dks.size();
    for(int i=0;i<t;i++){
        int dk=dks[i];
        for(int j=dk;j<n;j++){
            if(a[j]>=a[j-dk]){
                continue;
            }
            int target=a[j],k;
            for(k=j-dk;k>=0&&a[k]>target;k-=dk){
                a[k+dk]=a[k];
            }
            a[k+dk]=target;
        }
    }
    return;
}

void shellsort(vector<int> &a){
    //希尔排序 时间复杂度O(n^1.25)~O(1.6n^1.25) 空间复杂度O(1)
    vector<int> dk;
    int n=a.size()>>1;
    while(n>0){
        dk.push_back(n);
        n-=2;
    }
    if(n==0){
        dk.push_back(1);
    }
    shellsortCore(a,dk);
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    shellsort(a);
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