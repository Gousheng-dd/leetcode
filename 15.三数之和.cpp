/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.11%)
 * Likes:    3029
 * Dislikes: 0
 * Total Accepted:    432.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        if(nums[0]>0){
            return {};
        }
        vector<vector<int> > res;
        for(int i=0;i<nums.size()-2;i++){
            if(i&&nums[i-1]==nums[i]){
                continue;
            }
            int second=i+1,third=nums.size()-1;
            while(second<third){
                if(nums[i]+nums[second]+nums[third]==0){
                    vector<int> zerores={nums[i],nums[second],nums[third]};
                    res.push_back(zerores);
                    second++;
                    while(nums[second]==nums[second-1]&&second<third){
                        second++;
                    }
                }
                else if(nums[i]+nums[second]+nums[third]>0){
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

