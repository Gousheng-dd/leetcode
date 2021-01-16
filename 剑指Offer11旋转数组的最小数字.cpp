class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty()){
            return -1;
        }
        int l=0,r=numbers.size()-1,mid=0;
        while (numbers[l]>=numbers[r]){
            if(r-l==1){//结束条件
                return numbers[r];
            }
            mid=(l+r)/2;
            if(numbers[mid]==numbers[l]&&numbers[mid]==numbers[r]){//此时需要直接遍历
                int minnum=numbers[0];
                for(int i=1;i<numbers.size();i++){
                    minnum=min(minnum,numbers[i]);
                }
                return minnum;
            }
            if(numbers[mid]>=numbers[l]){
                l=mid;
            }
            else if(numbers[mid]<=numbers[r]){
                r=mid;
            }
        }
        return numbers[mid];
    }
};