class Solution {
public:
    int findNthDigit(int n) {
        if(n<0){
            return -1;
        }
        if(n<10){
            return n;
        }
        long long dig=10;
        int num=1;
        while(n>=dig*num){
            n-=dig*num;
            if(dig==10){
                dig=90;
            }
            else{
                dig*=10;
            }
            num++;
        }
        int startnum=int(pow(10,num-1));
        int restnum=n%num;
        n/=num;
        n+=startnum;
        for(int i=1;i<num-restnum;i++){
            n/=10;
        }
        return n%10;
    }
};