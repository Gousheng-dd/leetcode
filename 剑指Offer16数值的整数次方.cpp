class Solution {
public:
    const double eps=1e-6;
    double myPow(double x, int n) {
        if(fabs(x-0.0)<eps&&n==0){
            return -1.0;
        }
        int flag=0;
        long long exp=n;
        double res=1;
        if(n<0){
            flag=1;
            exp=-exp;
        }
        while(exp){//快速幂
            if(exp&1){
                res*=x;
            }
            x*=x;
            exp=exp>>1;
        }
        return (flag==1)?1/res:res;
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {//计算幂时超时
//         if(x==0&&n==0){
//             return -1.0;
//         }
//         int flag=0;
//         unsigned exp;
//         double res=1;
//         if(n<0){
//             flag=1;
//             exp=unsigned(-n);
//         }
//         else{
//             exp=unsigned(n);
//         }
//         for(int i=0;i<exp;i++){
//             res*=x;
//         }
//         if(flag){
//             res=1/res;
//         }
//         return res;
//     }
// };