class Solution {
public:
    int majorityElement(vector<int>& nums) {

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