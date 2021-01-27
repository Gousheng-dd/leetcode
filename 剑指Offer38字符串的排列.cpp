class Solution {
public:
    vector<string> permutation(string s) {
        if(s.size()==0){
            return {};
        }
        getPermutation(s,0);
        return res;
    }
private:
    vector<string> res;

    void getPermutation(string &s,int idx){
        if(idx==s.size()){
            res.push_back(s);
            return;
        }
        for(int i=idx;i<s.size();i++){
            bool flag=false;
            for(int j=idx;j<i;j++){
                if(s[i]==s[j]){
                    flag=true;
                }
            }
            if(flag){
                continue;
            }
            int tem=s[idx];
            s[idx]=s[i];
            s[i]=tem;
            getPermutation(s,idx+1);
            tem=s[idx];
            s[idx]=s[i];
            s[i]=tem;
        }
    }
};