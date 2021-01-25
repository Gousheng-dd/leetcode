/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 *
 * https://leetcode-cn.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (60.32%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 29.4K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * 给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop
 * 操作序列的结果时，返回 true；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * 输出：true
 * 解释：我们可以按以下顺序执行：
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 * 
 * 
 * 示例 2：
 * 
 * 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * 输出：false
 * 解释：1 不能在 2 之前弹出。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed 是 popped 的排列。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0&&popped.size()==0){
            return true;
        }
        if(pushed.size()==0||popped.size()==0){
            return false;
        }
        stack<int> s;
        while(!s.empty()){
            s.pop();
        }
        int pushidx=0,popidx=0;
        while(popidx<popped.size()){
            if(s.empty()){
                if(pushidx==pushed.size()){
                    break;
                }
                else{
                    s.push(pushed[pushidx++]);
                }
            }
            while(s.top()!=popped[popidx]&&pushidx<pushed.size()){
                s.push(pushed[pushidx++]);
            }
            if(s.top()!=popped[popidx]){
                break;
            }
            while((!s.empty())&&s.top()==popped[popidx]){
                s.pop();
                popidx++;
            }
        }
        if(popidx==popped.size()){
            return true;
        }
        return false;
    }
};
// @lc code=end

