/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (65.41%)
 * Likes:    851
 * Dislikes: 0
 * Total Accepted:    258.1K
 * Total Submissions: 393.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3,2,3]
 * 输出：3
 * 
 * 示例 2：
 * 
 * 
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int cnt=1,num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(!cnt){
                num=nums[i];
                cnt=1;
            }
            else{
                if(nums[i]==num){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        if(!checkMoreThanHalf(nums,num)){
            return -1;
        }
        return num;
    }
private:
    bool checkMoreThanHalf(vector<int>& nums,int val){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                cnt++;
            }
        }
        if(cnt>nums.size()/2){
            return true;
        }
        return false;
    }
};
// @lc code=end

