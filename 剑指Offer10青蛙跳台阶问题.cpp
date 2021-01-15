class Solution {
public:
    int numWays(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        int fibone=1,fibtwo=1,fib=0;
        for(int i=2;i<=n;i++){
            fib=(fibone+fibtwo) % 1000000007;
            fibtwo=fibone;
            fibone=fib;
        }
        return fib;
    }
};