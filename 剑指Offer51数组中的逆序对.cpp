class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int n=nums.size();
        vector<int> copy;
        for(int i=0;i<n;i++){
            copy.push_back(nums[i]);
        }
        int res=countReversePairs(nums,copy,0,n-1);
        return res;
    }
private:
    int countReversePairs(vector<int>& nums,vector<int>& copy,int start,int end){
        if(start==end){
            copy[start]=nums[start];
            return 0;
        }
        int len=(end-start+1)>>1;
        int p1=start+len-1,p2=end,p3=end;
        int cnt=0;
        cnt+=countReversePairs(copy,nums,start,p1);
        cnt+=countReversePairs(copy,nums,p1+1,end);
        while(p1>=start&&p2>=start+len){
            if(nums[p1]>nums[p2]){
                cnt+=(p2-(start+len)+1);
                copy[p3--]=nums[p1--];
            }
            else{
                copy[p3--]=nums[p2--];
            }
        }
        for(;p1>=start;p1--){
            copy[p3--]=nums[p1];
        }
        for(;p2>=start+len;p2--){
            copy[p3--]=nums[p2];
        }
        return cnt;
    }
};