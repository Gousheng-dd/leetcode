/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (41.13%)
 * Likes:    976
 * Dislikes: 0
 * Total Accepted:    123K
 * Total Submissions: 298.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        int minnum=1,maxnum=1,res=INT_MIN;
        for(int i=0;i<n;i++){
            int maxn=maxnum,minn=minnum;
            maxnum=max(maxn*nums[i],max(nums[i],minn*nums[i]));
            minnum=min(maxn*nums[i],min(nums[i],minn*nums[i]));
            res=max(res,maxnum);
        }
        return res;
    }
};
// @lc code=end

