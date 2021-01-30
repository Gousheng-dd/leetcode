class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int n=s.size();
        int res=1,nowlen=1;
        int hash[256];
        for(int i=0;i<256;i++){
            hash[i]=-1;
        }
        hash[s[0]]=0;
        for(int i=1;i<n;i++){
            if(hash[s[i]]==-1||i-hash[s[i]]>nowlen){
                nowlen++;
            }
            else{
                nowlen=i-hash[s[i]];
            }
            if(res<nowlen){
                res=nowlen;
            }
            hash[s[i]]=i;
        }
        return res;
    }
};