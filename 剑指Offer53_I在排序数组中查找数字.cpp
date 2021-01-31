class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        int start=0,end=nums.size()-1;
        int left=getFirstk(nums,target,start,end);
        int right=getLastk(nums,target,start,end);
        if(left==-1||right==-1){
            return 0;
        }
        return right-left+1;
    }
private:
    int getFirstk(vector<int>& nums,int target,int begin,int end){
        if(begin>end){
            return -1;
        }
        int mid=(begin+end)>>1;
        if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]<target){
            begin=mid+1;
        }
        else{
            if((mid-1>=0&&nums[mid-1]!=target)||mid==0){
                return mid;
            }
            end=mid-1;
        }
        return getFirstk(nums,target,begin,end);
    }
    int getLastk(vector<int>& nums,int target,int begin,int end){
        if(begin>end){
            return -1;
        }
        int mid=(begin+end)>>1;
        if(nums[mid]>target){
            end=mid-1;
        }
        else if(nums[mid]<target){
            begin=mid+1;
        }
        else{
            if((mid+1<=nums.size()-1&&nums[mid+1]!=target)||mid==nums.size()-1){
                return mid;
            }
            begin=mid+1;
        }
        return getLastk(nums,target,begin,end);
    }
};