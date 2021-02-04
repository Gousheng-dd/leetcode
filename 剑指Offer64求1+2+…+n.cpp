class Solution {
public:
    int sumNums(int n) {
        int sum=n;
        bool flag=(n>0)&&(sum+=sumNums(n-1));
        return sum;
    }
};