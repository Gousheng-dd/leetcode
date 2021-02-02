class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(s.size()==0||n<=0||n>s.size()){
            return s;
        }
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.end()-n);
        reverse(s.end()-n,s.end());
        return s;
    }
};