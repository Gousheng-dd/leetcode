class Solution {
public:
    int add(int a, int b) {
        int res,carry;
        do{
            res=a^b;
            carry=(unsigned int)(a&b)<<1;
            a=res;
            b=carry;
        }while(b);
        return res;
    }
};