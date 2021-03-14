/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.47%)
 * Likes:    695
 * Dislikes: 0
 * Total Accepted:    107K
 * Total Submissions: 215.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //暴力，TLE
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return true;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2){
            return false;
        }
        sum/=2;
        return canGetSumN(nums,sum,0,0);
    }
private:
    bool canGetSumN(vector<int> &nums,int n,int nowsum,int idx){
        if(nowsum>n||idx==nums.size()){
            return false;
        }
        if(nowsum==n){
            return true;
        }
        return canGetSumN(nums,n,nowsum+nums[idx],idx+1)||
                canGetSumN(nums,n,nowsum,idx+1);
        
    }
};
// @lc code=end

