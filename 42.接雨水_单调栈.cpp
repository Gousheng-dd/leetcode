/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (54.58%)
 * Likes:    2105
 * Dislikes: 0
 * Total Accepted:    203.5K
 * Total Submissions: 372.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //单调栈,后续结果影响前面多个的情况
    int trap(vector<int>& height) {
        if(height.size()<=1){
            return 0;
        }
        stack<int> s;
        int res=0;
        s.push(0);
        for(int i=1;i<height.size();i++){
            if(s.empty()){
                s.push(i);
                continue;
            }
            if(height[s.top()]>height[i]){
                s.push(i);
                continue;
            }
            while(height[s.top()]<=height[i]){
                int toph=height[s.top()];
                s.pop();
                if(s.empty()){
                    break;
                }
                res+=(i-s.top()-1)*(min(height[i],height[s.top()])-toph);
            }
            s.push(i);
        }

        return res;
    }
};
// @lc code=end

