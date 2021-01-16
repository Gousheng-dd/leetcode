class Solution {
public:
    int cuttingRope(int n) {
        if(n<=2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int product[n+1];
        memset(product,0,sizeof product);
        product[0]=0;
        product[1]=1;
        product[2]=2;
        product[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                product[i]=max(product[i],product[j]*product[i-j]);
            }
        }
        return product[n];
    }
};