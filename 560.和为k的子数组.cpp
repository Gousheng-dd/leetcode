/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.86%)
 * Likes:    806
 * Dislikes: 0
 * Total Accepted:    94.8K
 * Total Submissions: 211.7K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*统计前i项和，
    若要第j+1项到第i项和为k则需要sum[i]-sum[j]==k，
    即sum[j]==sum[i]-k;
    则对当前i只需统计之前部分和中值为sum[i]-k的
    */
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        int pre=0,res=0;
        unordered_map<int,int> ump;
        ump[0]=1;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            if(ump.find(pre-k)!=ump.end()){
                res+=ump[pre-k];
            }
            if(ump.find(pre)!=ump.end()){
                ump[pre]++;
            }
            else{
                ump[pre]=1;
            }
        }
        return res;
    }
};
// @lc code=end

