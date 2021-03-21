#include<iostream>
#include<vector>

using namespace std;

int qsortCore(vector<int> &a,int begin,int end){
    int target=a[begin];
    int left=begin,right=end;
    while(left<right){
        while(left<right&&a[right]>=target){
            right--;
        }
        a[left]=a[right];
        while(left<right&&a[left]<=target){
            left++;
        }
        a[right]=a[left];
    }
    a[left]=target;
    return left;
}

//快速排序 平均时间复杂度O(nlogn)，最坏情况（天然有序）时为O(n^2); 空间复杂度O(logn)
//为了解决天然有序效率降低问题可以采用  三数取中+聚类，即在qsortcore中以a[begin],a[end],a[(begin+end)/2]的中间值作为轴
//聚类：在一次排序后将等于轴的数字聚集到轴两侧
void quicksort(vector<int> &a,int begin,int end){
    if(end<=begin){
        return;
    }
    int mid=qsortCore(a,begin,end);
    quicksort(a,begin,mid-1);
    quicksort(a,mid+1,end);
    return;
}

void test(){
    vector<int> a={1,5,8,6,50,6,9};
    int n=a.size();
    quicksort(a,0,n-1);
    for(auto it=a.begin();it!=a.end();it++){
        cout<<*it<<'\t';
    }
    cout<<endl;
    return;
}

int main()
{
    test();
    return 0;
}