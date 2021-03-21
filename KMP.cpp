#include<iostream>
#include<string>
#include<vector>

using namespace std;

void getNext(vector<int> &next,string &s){
    int n=s.size();
    next[1]=0;
    int i=1,j=0;
    while(i<n){
        if(j==0||s[i-1]==s[j-1]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
    return;
}

int kmp(string &a,string &b){
    int n=a.size(),m=b.size();
    vector<int> next(m+1);
    getNext(next,b);
    int i=1,j=1;
    while(i<=n&&j<=m){
        if(j==0||a[i-1]==b[j-1]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>m){
        return i-m-1;
    }
    else{
        return -1;
    }
}

bool test(){
    string a="ababcaabcab",b="abcab";
    if(kmp(a,b)==6){
        return true;
    }
    return false;
}

int main()
{
    cout<<test()<<endl;
}