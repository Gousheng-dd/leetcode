class Solution {
public:
    vector<int> printNumbers(int n) {
        int maxnum=int(pow(10,n));
        vector<int> res;
        for(int i=1;i<maxnum;i++){
            res.push_back(i);
        }
        return res;
    }
};