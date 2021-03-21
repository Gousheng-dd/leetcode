#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &a,int begin,int mid,int end){
    //将数组a的[begin,mid]和[mid+1,end]合并到b的[begin,end]中
    int *tem=new int[end-begin+1];
    int i=begin,j=mid+1,idx=0;
    while(i<=mid&&j<=end){
        if(a[i]<a[j]){
            tem[idx++]=a[i++];
        }
        else{
            tem[idx++]=a[j++];
        }
    }
    while(i<=mid){
        tem[idx++]=a[i++];
    }
    while(j<=end){
        tem[idx++]=a[j++];
    }
    for(int i=0;i<end-begin+1;i++){
        a[i+begin]=tem[i];
    }
    delete []tem;
    return;
}

void mergesort(vector<int> &a,int begin,int end){
    //归并排序 时间复杂度O(nlogn) 空间复杂度O(n)
    if(begin==end){
        return;
    }
    int mid=(begin+end)>>1;
    mergesort(a,begin,mid);
    mergesort(a,mid+1,end);
    merge(a,begin,mid,end);
    return;
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    mergesort(a,0,6);
    for(int i=0;i<7;i++){
        cout<<a[i]<<'\t';
    }
    cout<<endl;
    return;
}

int main()
{
    test();
    return 0;
}