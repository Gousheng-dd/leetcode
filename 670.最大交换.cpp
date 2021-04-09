/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 *
 * https://leetcode-cn.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 30K
 * Testcase Example:  '2736'
 *
 * 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
 * 
 * 示例 1 :
 * 
 * 
 * 输入: 2736
 * 输出: 7236
 * 解释: 交换数字2和数字7。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: 9973
 * 输出: 9973
 * 解释: 不需要交换。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数字的范围是 [0, 10^8]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        //第一趟从后往前记录每个位置之后最大的数，第二趟从前往后尽早替换O(n) O(n)
        if(num<=0){
            return 0;
        }
        int *numdig=new int[9];
        pair<int,int> *maxnum=new pair<int,int>[9];
        int nowmax=-1,maxidx,cnt=0,n=num;
        while(n){
            numdig[cnt]=n%10;
            if(numdig[cnt]>nowmax){
                nowmax=numdig[cnt];
                maxidx=cnt;
            }
            maxnum[cnt]=make_pair(nowmax,maxidx);
            n/=10;
            cnt++;
        }
        for(int i=cnt-1;i>=0;i--){
            if(maxnum[i].first>numdig[i]){
                swap(numdig[i],numdig[maxnum[i].second]);
                break;
            }
        }
        int res=numdig[cnt-1];
        for(int i=cnt-2;i>=0;i--){
            res*=10;
            res+=numdig[i];
        }
        delete []numdig;
        delete []maxnum;
        return res;
    }
};
// @lc code=end

