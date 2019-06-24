// 实现 int sqrt(int x) 函数。

// 计算并返回 x 的平方根，其中 x 是非负整数。

// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sqrtx
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <limits>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = 46340;
        long long mid; 
        while(l <= r) {
            mid = (l+r) >> 1;
            if(mid*mid <= x && (mid+1)*(mid+1) > x) { // 此处可能溢出
                return mid;
            }
            else if(mid*mid > x) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return mid;
    }
};