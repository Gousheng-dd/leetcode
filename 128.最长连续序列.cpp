/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (52.91%)
 * Likes:    710
 * Dislikes: 0
 * Total Accepted:    101.3K
 * Total Submissions: 191.3K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 
 * 
 * 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(!n){
            return 0;
        }
        unordered_set<int> s;
        unordered_set<int>::iterator it;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int nownum,res=1,cnt;
        for(it=s.begin();it!=s.end();it++){
            nownum=(*it);
            if(s.count(nownum-1)>0){
                continue;
            }
            cnt=1;
            while(s.count(nownum+1)){
                cnt++;
                nownum++;
            }
            res=max(res,cnt);
        }
        return res;
    }
};
// @lc code=end

