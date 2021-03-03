/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    702
 * Dislikes: 0
 * Total Accepted:    189.8K
 * Total Submissions: 413.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        int res;
        int mingap=0x3f3f3f3f;
        for(int i=0;i<nums.size()-2;i++){
            if(i&&nums[i-1]==nums[i]){
                continue;
            }
            int second=i+1,third=nums.size()-1;
            while(second<third){
                if(abs((nums[i]+nums[second]+nums[third])-target)<mingap){
                    res=nums[i]+nums[second]+nums[third];
                    mingap=abs((nums[i]+nums[second]+nums[third])-target);
                }
                if(nums[i]+nums[second]+nums[third]>target){
                    third--;
                    while(nums[third]==nums[third+1]&&second<third){
                        third--;
                    }
                }
                else{
                    second++;
                    while(nums[second]==nums[second-1]&&second<third){
                        second++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

