/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 照搬84解决方案即可
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st; st.push(-1); // 方便处理栈底的处理
        for(int i = 0;i < heights.size();i++) {
            // 此时找到了一个非递增的
            // 注意大于等于都可以
            while(st.top() != -1 && heights[st.top()] >= heights[i]) {
                int height_index = st.top(); st.pop();
                res = max(res, heights[height_index]*(i - 1 - st.top()));
            }
            st.push(i);
        }
        while(st.top() != -1) {
            int height_index = st.top(); st.pop();
            res = max(res, (int)(heights[height_index]*(heights.size() - st.top() - 1)));
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) {
            return 0;
        }
        int m = matrix[0].size(), res = 0;
        vector<int> heights(m, 0);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
};