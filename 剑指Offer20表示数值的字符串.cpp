#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(s.size()==0){
            return false;
        }
        int idx=0;
        ignoreSpace(s,idx);
        bool isnum=scanInteger(s,idx);
        if(s[idx]=='.'){
            idx++;
            isnum=scanUnsignedInteger(s,idx)||isnum;
        }
        if(s[idx]=='e'||s[idx]=='E'){
            idx++;
            isnum=isnum&&scanInteger(s,idx);
        }
        ignoreSpace(s,idx);
        return isnum&&idx==s.size();
    }
    void ignoreSpace(string& s,int& idx){
        while(idx<s.size()&&s[idx]==' '){
            idx++;
        }
        return;
    }
    bool scanUnsignedInteger(string& s,int& idx){
        bool flag=false;
        while(idx<s.size()&&s[idx]>='0'&&s[idx]<='9'){
            flag=true;
            idx++;
        }
        return flag;
    }
    bool scanInteger(string& s,int& idx){
        if(idx<s.size()&&(s[idx]=='+'||s[idx]=='-')){
            idx++;
        }
        return scanUnsignedInteger(s,idx);
    }
};

int main()
{
    Solution s;
    cout<<s.isNumber("0.8");
    return 0;
}