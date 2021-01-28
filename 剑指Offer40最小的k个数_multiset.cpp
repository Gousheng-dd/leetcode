class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size()==0||k>arr.size()||k<=0){
            return {};
        }
        multiset<int, greater<int> > kset;
        multiset<int, greater<int> >::iterator it;
        for(int i=0;i<arr.size();i++){
            if(kset.size()<k){
                kset.insert(arr[i]);
            }
            else{
                it=kset.begin();
                if(*it>arr[i]){
                    kset.erase(it);
                    kset.insert(arr[i]);
                }
            }
        }
        vector<int> res;
        for(it=kset.begin();it!=kset.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};