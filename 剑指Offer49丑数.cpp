class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0){
            return -1;
        }
        int* uglynum=new int[n+10];
        int *ugly2,*ugly3,*ugly5;
        ugly2=ugly3=ugly5=uglynum+1;
        int cnt=1;
        uglynum[1]=1;
        while(cnt<n){
            int u2=(*ugly2)*2,u3=(*ugly3)*3,u5=(*ugly5)*5;
            uglynum[++cnt]=min(u2,u3,u5);
            while((*ugly2)*2<=uglynum[cnt]){
                ugly2++;
            }
            while((*ugly3)*3<=uglynum[cnt]){
                ugly3++;
            }
            while((*ugly5)*5<=uglynum[cnt]){
                ugly5++;
            }
        }
        return uglynum[n];
    }
private:
    int min(int a,int b,int c){
        int res=a<b?a:b;
        return res<c?res:c;
    }
};