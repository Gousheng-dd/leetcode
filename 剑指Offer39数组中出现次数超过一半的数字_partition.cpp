class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mid=nums.size()>>1;
        int begin=0,end=nums.size()-1;
        int idx=Partition(nums,begin,end);
        while(idx!=mid){
            if(idx>mid){
                end=idx-1;
                idx=Partition(nums,begin,end);
            }
            else{
                begin=idx+1;
                idx=Partition(nums,begin,end);
            }
        }
        if(!checkMoreThanHalf(nums,nums[idx])){
            return -1;
        }
        return nums[idx];
    }
private:
    int Partition(vector<int>& nums,int begin,int end){
        int idx=getRandomInRange(begin,end);
        swap(&nums[idx],&nums[end]);
        int smallidx=begin-1;
        for(idx=begin;idx<end;idx++){
            if(nums[idx]<nums[end]){
                smallidx++;
                if(smallidx!=idx){
                    swap(&nums[smallidx],&nums[idx]);
                }
            }
        }
        smallidx++;
        swap(&nums[smallidx],&nums[end]);
        return smallidx;
    }

    void swap(int* a,int* b){
        int tem=*a;
        *a=*b;
        *b=tem;
        return;
    }

    int getRandomInRange(int begin,int end){
        return begin+rand()%(end-begin+1);
    }

    bool checkMoreThanHalf(vector<int>& nums,int val){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                cnt++;
            }
        }
        if(cnt>nums.size()/2){
            return true;
        }
        return false;
    }
};