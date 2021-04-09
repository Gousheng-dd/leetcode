#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

void printStrNum(int n,char *num)
{
    int idx=0,flag=0;
    while(num[idx]=='0'){
        idx++;
    }
    while(idx<n){
        flag=1;
        printf("%c",num[idx++]);
    }
    if(flag){
        printf("\n");
    }
    return;
}

void generateNumbers(char *s,int len,int idx){
    if(idx==len){
        printStrNum(len,s);
        return;
    }
    for(int i=0;i<10;i++){
        s[idx]='0'+i;
        generateNumbers(s,len,idx+1);
    }
    return;
}

void printNumbers(int n)
{
    if(n<0){
        return;
    }
    if(n==0){
        printf("1\n");
        return;
    }
    char* num=new char[n+1];
    for(int i=0;i<n;i++){
        num[i]='0';
    }
    num[n]='\0';
    generateNumbers(num,n,0);
    return ;
}

int main()
{
    int testn=2;
    printNumbers(testn);
    return 0;
}