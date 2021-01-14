class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //二分（本题不适用，需要1~n-1才行，而本题为0~n-1）
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(r+l)>>1;
            int cnt=cntnum(nums,l,mid);
            if(cnt>mid-l+1){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    int cntnum(vector<int>& nums,int min,int max) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=min&&nums[i]<=max){
                cnt++;
            }
        }
        return cnt;
    }
};