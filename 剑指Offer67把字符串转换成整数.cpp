class Solution {
public:
    int strToInt(string str) {
        if(str.size()==0){
            return 0;
        }
        bool flag=false;
        int idx=0,res=0,len=str.size();
        while(idx<len&&str[idx]==' '){
            idx++;
        }
        if(idx<len&&str[idx]=='-'){
            flag=true;
            idx++;
        }
        else if(idx<len&&str[idx]=='+'){
            idx++;
        }
        
        while(idx<len){
            if(str[idx]<'0'||str[idx]>'9'){
                break;
            }
            if(res>INT_MAX/10||(res==INT_MAX/10&&str[idx]-'0'>7)){
                return flag?INT_MIN:INT_MAX;
            }
            res*=10;
            res+=str[idx]-'0';
            idx++;
        }
        if(flag){
            res=-res;
        }
        return res;
    }
};