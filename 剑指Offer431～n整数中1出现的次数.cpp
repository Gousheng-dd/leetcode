class Solution {
public:
    int countDigitOne(int n) {
        if(n<0){
            return -1;
        }
        long long digit=1;
        int cnt=0,high=n/10,low=0,cur=n%10;
        while(high||cur){
            if(cur==0){
                cnt+=high*digit;
            }
            else if(cur==1){
                cnt+=high*digit+low+1;
            }
            else{
                cnt+=(high+1)*digit;
            }
            low+=digit*cur;
            cur=high%10;
            high/=10;
            digit*=10;
        }
        return cnt;
    }
};