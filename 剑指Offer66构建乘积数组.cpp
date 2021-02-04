class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size()==0){
            return {};
        }
        int left=1,right=1,n=a.size();
        vector<int> res;
        for(int i=0,pro=1;i<n;pro*=a[i],i++){
            res.push_back(pro);
        }
        for(int i=n-1,pro=1;i>=0;pro*=a[i],i--){
            res[i]*=pro;
        }
        return res;
    }
};