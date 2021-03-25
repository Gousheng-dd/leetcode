/*看做每个物品体积价值都相等等于硬币面额，背包容量为w时最大价值一定小于等于w*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *coins=new int[n];
    int *dp=new int[m+1];
    memset(dp,0,sizeof(int)*(m+1));
    bool **choice=new bool*[n];
    for(int i=0;i<n;i++){
        choice[i]=new bool[m+1];
        memset(choice[i],0,sizeof(bool)*(m+1));
    }
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    sort(coins,coins+n,greater<int>());
    for(int i=0;i<n;i++){
        for(int j=m;j>=coins[i];j--){
            if(dp[j]<=dp[j-coins[i]]+coins[i]){
                dp[j]=dp[j-coins[i]]+coins[i];
                choice[i][j]=true;
            }
        }
    }
    if(dp[m]!=m){
        printf("No Solution\n");
        return 0;
    }
    int cnt=0;
    int *res=new int[n];
    for(int i=n-1;i>=0;i--){
        if(choice[i][m]){
            res[cnt++]=coins[i];
            m-=coins[i];
        }
    }
    printf("%d",res[0]);
    for(int i=1;i<cnt;i++){
        printf(" %d",res[i]);
    }
    printf("\n");
    delete[]coins;
    delete[]dp;
    delete[]res;
    for(int i=0;i<n;i++){
        delete []choice[i];
    }
    delete []choice;
    return 0;
}