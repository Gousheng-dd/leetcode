class Solution {
public:
    vector<double> dicesProbability(int n) {
        if(n<=0){
            return {};
        }
        int* tot[2];
        tot[0]=new int[maxnum*n+1];
        tot[1]=new int[maxnum*n+1];
        int current=0;
        for(int i=0;i<=maxnum*n;i++){
            tot[0][i]=tot[1][i]=0;
        }
        for(int i=1;i<=maxnum;i++){
            tot[0][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                tot[1-current][j]=0;
            }
            for(int j=i;j<=maxnum*i;j++){
                tot[1-current][j]=0;
                for(int k=1;k<=maxnum&&k<j;k++){
                    tot[1-current][j]+=tot[current][j-k];
                }
            }
            current=1-current;
        }
        vector<double> res;
        double totnum=pow(double(maxnum),n);
        for(int i=n;i<=maxnum*n;i++){
            res.push_back(tot[current][i]/totnum);
        }
        return res;
    }
private:
    int maxnum=6;
};