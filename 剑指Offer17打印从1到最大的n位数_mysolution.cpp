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
    int flag=0;
    while(1){
        for(int j=0;j<10;j++){
            num[n-1]='0'+j;
            printStrNum(n,num);
            if(j==9){
                if(n==1){
                    flag=1;
                    break;
                }
                int idx=n-2;
                while(num[idx]=='9'){
                    num[idx]='0';
                    idx--;
                    if(idx<0){
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    break;
                }
                num[idx]++;
            }
        }
        if(flag){
            break;
        }
    }
    delete []num;
    return;
}

int main()
{
    int testn=5;
    printNumbers(testn);
    return 0;
}