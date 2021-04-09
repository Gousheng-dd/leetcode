#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

void printStrNum(char* nums,int len){
    int idx=0;
    bool flag=false;
    while(idx<len&&nums[idx]=='0'){
        idx++;
    }
    while(idx<len){
        flag=true;
        printf("%c",nums[idx]);
        idx++;
    }
    if(flag){
        printf("\n");
    }
    return;
}

void printNumbers(int n)
{
    if(n<=0){
        return;
    }
    char *nums=new char[n+1];
    for(int i=0;i<n;i++){
        nums[i]='0';
    }
    nums[n]='\0';
    while(1){
        printStrNum(nums,n);
        int idx=n-1;
        while(nums[idx]=='9'){
            nums[idx]='0';
            idx--;
            if(idx==-1){
                return;
            }
        }
        nums[idx]++;
    }
    return ;
}

int main()
{
    int testn=2;
    printNumbers(testn);
    return 0;
}