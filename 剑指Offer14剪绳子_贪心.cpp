class Solution {
public:
    int cuttingRope(int n) {
        if(n<=2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int time3=n/3,time2=(n-time3*3)/2;
        if(n-time3*3==1){
            time3--;
            time2=2;
        }
        long long res=long long(pow(2,time2));
        for(int i=0;i<time3;i++){
            res*=3;
            res%=1000000007;
        }
        return (int)res;
    }
};