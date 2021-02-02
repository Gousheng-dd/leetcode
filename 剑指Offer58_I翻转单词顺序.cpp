class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0){
            return s;
        }
        string::iterator start=s.begin(),end=s.end()-1,tem;
        while(*end==' '){
            s.erase(end);
            end=s.end()-1;
        }
        reverse(s.begin(),s.end());
        end=s.end()-1;
        while(*end==' '){
            s.erase(end);
            end=s.end()-1;
        }
        end=s.begin();
        while(end!=s.end()){
            if(*end==' '){
                reverse(start,end);
                end++;
                while(end!=s.end()&&*end==' '){
                    s.erase(end);
                }
                start=end;
            }
            else{
                end++;
            }
        }
        reverse(start,end);
        return s;
    }
};