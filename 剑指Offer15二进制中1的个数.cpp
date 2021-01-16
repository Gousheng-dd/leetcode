class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        uint32_t flag=1;
        while (flag){
            if(n&flag){
                cnt++;
            }
            flag=flag<<1;
        }
        return cnt;
    }
};