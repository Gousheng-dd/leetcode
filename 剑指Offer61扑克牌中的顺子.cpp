class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size()!=5){
            return false;
        }
        int neednum=0,zeronum=0,now=0,pre=0;
        sort(nums.begin(),nums.end(),cmp);
        for(;now<=4;now++){
            if(nums[now]==0){
                zeronum++;
                pre++;
                continue;
            }
            if(now!=0&&nums[now-1]!=0){
                if(now!=pre&&nums[now]==nums[pre]){
                    return false;
                }
                neednum+=nums[now]-nums[pre]-1;
                pre=now;
            }
        }
        if(zeronum>=neednum){
            return true;
        }
        return false;
    }
private:
    static bool cmp(int a,int b){
        return a<b;
    }
};