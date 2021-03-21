#include<iostream>
#include<vector>

using namespace std;

void downadjust(vector<int> &a,int now,int n){
    int current=now,tem=a[now],child=now*2+1;
    while(child<=n){
        if(child<n&&a[child]<a[child+1]){
            child++;
        }
        if(tem>=a[child]){
            break;
        }
        a[current]=a[child];
        current=child;
        child=current*2+1;
    }
    a[current]=tem;
    return;
}

void createHeap(vector<int> &a){
    int n=a.size();
    for(int i=n/2;i>=0;i--){
        downadjust(a,i,n-1);
    }
    return;
}

void heapsort(vector<int> &a){
    //堆排序 时间复杂度O(nlogn) 空间复杂度O(1)
    createHeap(a);
    int n=a.size();
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        downadjust(a,0,i-1);
    }
    return;
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    heapsort(a);
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