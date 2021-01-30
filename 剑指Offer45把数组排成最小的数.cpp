class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(nums.size()==0){
            return "";
        }
        int n=nums.size();
        vector<string> snum;
        for(int i=0;i<n;i++){
            snum.push_back(to_string(nums[i]));
        }
        sort(snum.begin(),snum.end(),cmp);
        string res;
        for(int i=0;i<n;i++){
            res.append(snum[i]);
        }
        return res;
    }
private:
    static bool cmp(string &a,string &b){
        return a+b<b+a;
    }
};