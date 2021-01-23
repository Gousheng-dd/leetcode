class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchCore(s,p,0,0);
    }
private:
    bool isMatchCore(string& s,string& p,int sidx,int pidx) {
        if(sidx==s.size()&&pidx==p.size()){
            return true;
        }
        if(sidx>s.size()||pidx>p.size()){
            return false;
        }
        if(sidx!=s.size()&&pidx==p.size()){
            return false;
        }
        if(pidx+1==p.size()||p[pidx+1]!='*'){
            if(s[sidx]==p[pidx]||p[pidx]=='.'){
                return isMatchCore(s,p,sidx+1,pidx+1);
            }
            else{
                return false;
            }
        }
        else{
            if(s[sidx]==p[pidx]||p[pidx]=='.'){
                return isMatchCore(s,p,sidx+1,pidx+2)
                        ||isMatchCore(s,p,sidx+1,pidx)
                        ||isMatchCore(s,p,sidx,pidx+2);
            }
            else{
                return isMatchCore(s,p,sidx,pidx+2);
            }
        }
    }
};