#include<iostream>
#include<string>
#include<stack>

#define MAXNUM 100010

using namespace std;
//树状数组，单点更新区间查询

int c[MAXNUM];
stack<int> s;

int lowbit(int x){
    return x&(-x);
}

void update(int x,int value){
    for(int i=x;i<MAXNUM;i+=lowbit(i)){
        c[i]+=value;
    }
    return;
}

int getSum(int x){
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}

void mypop(){
    if(s.empty()){
        cout<<"Invalid"<<endl;
        return;
    }
    int x=s.top();
    s.pop();
    update(x,-1);
    cout<<x<<endl;
    return ;
}

void mypush(int value){
    update(value,1);
    s.push(value);
    return;
}

void peekMedian(){
    if(s.empty()){
        cout<<"Invalid"<<endl;
        return;
    }
    int begin=0,end=MAXNUM-1;
    int median=(s.size()+1)>>1;
    while(begin<end){
        int mid=(begin+end)>>1;
        if(getSum(mid)>=median){
            end=mid;
        }
        else{
            begin=mid+1;
        }
    }
    cout<<begin<<endl;
    return ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string cmd;
        cin>>cmd;
        if(cmd=="Pop"){
            mypop();
        }
        else if(cmd=="Push"){
            int value;
            cin>>value;
            mypush(value);
        }
        else{
            peekMedian();
        }
    }
    return 0;
}