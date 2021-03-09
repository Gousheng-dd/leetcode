/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (66.16%)
 * Likes:    672
 * Dislikes: 0
 * Total Accepted:    138.9K
 * Total Submissions: 209.6K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
 * 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
class Solution {
public:
    //单调栈，从大到小，查询每个位置大于他的
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        if(n==0){
            return {};
        }
        vector<int > res(n);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            if(s.empty()){
                s.push(i);
                break;
            }
            while(T[i]>T[s.top()]){
                res[s.top()]=i-s.top();
                s.pop();
                if(s.empty()){
                    break;
                }
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()]=0;
            s.pop();
        }
        return res;
    }
};
// @lc code=end

