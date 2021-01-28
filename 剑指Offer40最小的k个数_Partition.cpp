class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size()==0||k<=0||k>arr.size()){
            return {};
        }
        int begin=0,end=arr.size()-1;
        int idx=Partition(arr,begin,end);
        while(idx!=k-1){
            if(idx==-1){
                return {};
            }
            if(idx<k-1){
                begin=idx+1;
                idx=Partition(arr,begin,end);
            }
            else{
                end=idx-1;
                idx=Partition(arr,begin,end);
            }
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
private:
    int Partition(vector<int>& nums,int begin,int end){
        if(begin>end){
            return -1;
        }
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
};