class Solution {
public:
    char firstUniqChar(string s) {
        if(s.size()==0){
            return ' ';
        }
        int hash[256];
        memset(hash,0,sizeof hash);
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==1){
                return s[i];
            }
        }
        return ' ';
    }
};