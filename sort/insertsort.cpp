#include<iostream>
#include<vector>

using namespace std;

void insertsort(vector<int> &a){
    //折半插入排序 时间复杂度O(n^2) 空间复杂度O(1)
    int n=a.size();
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){
            continue;
        }
        int target=a[i];
        int begin=0,end=i-1;
        while(begin<end){
            int mid=(begin+end)>>1;
            if(a[mid]>target){
                end=mid;
            }
            else{
                begin=mid+1;
            }
        }
        //从begin到i-1都向后移一位
        for(int j=i-1;j>=begin;j--){
            a[j+1]=a[j];
        }
        a[begin]=target;
    }
    return;
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    insertsort(a);
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