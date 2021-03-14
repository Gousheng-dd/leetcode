/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (47.85%)
 * Likes:    1436
 * Dislikes: 0
 * Total Accepted:    223.7K
 * Total Submissions: 465K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以设计时间复杂度为 O(n^2) 的解决方案吗？
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //贪心+二分，数组d[i]表示长度为i的子序列的最小的末尾元素
    //若当前数字大于d[len]：len++,添加到d[len]
    //否则在d[0...len]中查找大于nums[i]的位置，替换
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        vector<int> d;
        d.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>d[len-1]){
                d.push_back(nums[i]);
                len++;
                continue;
            }
            else if(nums[i]==d[len-1]){
                continue;
            }
            int begin=0,end=len-1;
            while(begin<end){
                int mid=(begin+end)>>1;
                if(d[mid]==nums[i]){
                    begin=mid;
                    break;
                }
                if(d[mid]>nums[i]){
                    end=mid;
                }
                else{
                    begin=mid+1;
                }
            }
            d[begin]=nums[i];
        }
        return len;
    }
};
// @lc code=end

