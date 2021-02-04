class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int n=prices.size(),nowmin=0x3f3f3f3f,res=0;
        for(int i=0;i<n;i++){
            if(prices[i]-nowmin>res){
                res=prices[i]-nowmin;
            }
            if(prices[i]<nowmin){
                nowmin=prices[i];
            }
        }
        return res;
    }
};