/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (56.76%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 32.2K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。
 * 
 * 实现 NumArray 类：
 * 
 * 
 * 
 * 
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值更新为 val
 * int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] +
 * nums[left + 1], ..., nums[right]）
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 * 
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -100 
 * 0 
 * -100 
 * 0 
 * 最多调用 3 * 10^4 次 update 和 sumRange 方法
 * 
 * 
 * 
 * 
 */

// @lc code=start
class NumArray {
public:
    //线段树
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree=new int[n<<2];
        build_tree(nums,1,1,n);
        return;
    }
    
    void update(int index, int val) {
        update_tree(index+1,val,1,1,n);
        return ;
    }
    
    int sumRange(int left, int right) {
        return query_tree(left+1,right+1,1,1,n);
    }
private:
    int *tree;
    int n;
    void build_tree(vector<int> &nums,int idx,int begin,int end){
        if(begin==end){
            tree[idx]=nums[begin-1];
            return;
        }
        int mid=(begin+end)/2;
        int lc=idx<<1;
        int rc=idx<<1|1;
        build_tree(nums,lc,begin,mid);
        build_tree(nums,rc,mid+1,end);
        tree[idx]=tree[lc]+tree[rc];
        return;
    }
    void update_tree(int idx,int val,int node,int begin,int end){
        if(begin==end){
            tree[node]=val;
            return ;
        }
        int mid=(begin+end)/2;
        int lc=node<<1;
        int rc=node<<1|1;
        if(idx>=begin&&idx<=mid){
            update_tree(idx,val,lc,begin,mid);
        }
        else{
            update_tree(idx,val,rc,mid+1,end);
        }
        tree[node]=tree[lc]+tree[rc];
        return;
    }
    //[begin,end]为更新区间，[left,right]为当前区间
    int query_tree(int begin,int end,int node,int left,int right){
        if(left>end||right<begin){
            return 0;
        }
        if(left>=begin&&right<=end){
            return tree[node];
        }
        int mid=(left+right)/2;
        int lc=node<<1;
        int rc=node<<1|1;
        return query_tree(begin,end,lc,left,mid)+query_tree(begin,end,rc,mid+1,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

