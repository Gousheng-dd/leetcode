class Solution {
public:
    string replaceSpace(string s) {
        if(s.length()==0){
            return s;
        }
        string res;
        int len=s.length();
        int spacenum=0;
        for(int i=0;i<len;i++){
            if(s[i]==' '){
                spacenum++;
            }
        }
        int newlen=len+2*spacenum;
        s+=string(spacenum*2,' ');
        int idx=len-1,newidx=newlen-1;
        while(newidx>idx){
            if(s[idx]==' '){
                s[newidx--]='0';
                s[newidx--]='2';
                s[newidx--]='%';
            }
            else{
                s[newidx--]=s[idx];
            }
            idx--;
        }
        return s;
    }
};