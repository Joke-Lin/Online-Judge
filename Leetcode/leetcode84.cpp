// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 分治法 偶尔通过。。。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return divide(heights, 0, heights.size() - 1);
    }

    int divide(vector<int>& heights, int l, int r) {
        if(l > r) {
            return 0;
        }
        int min_index = l;
        for(int i = l;i <= r;i++) {
            if(heights[i] < heights[min_index]) {
                min_index = i;
            }
        }
        int area = heights[min_index]*(r-l+1);
        area = max(area, divide(heights, l, min_index-1));
        area = max(area, divide(heights, min_index+1, r));
        return area;
    }
};

// 栈
class Solution {
public:
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
};