// 给定两个二进制字符串，返回他们的和（用二进制表示）。

// 输入为非空字符串且只包含数字 1 和 0。

// 示例 1:

// 输入: a = "11", b = "1"
// 输出: "100"
// 示例 2:

// 输入: a = "1010", b = "1011"
// 输出: "10101"

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/add-binary
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int a_len = a.length(), b_len = b.length();
        int max_len = max(a_len, b_len);
        int get = 0;
        int temp = 0;
        for(int i = 0;i < max_len;i++) {
            temp = 0;
            if(i < a_len) temp += a[i]-'0';
            if(i < b_len) temp += b[i]-'0';
            temp += get;
            res.push_back(temp % 2 + '0');
            get = temp / 2;
        }
        if(get != 0) {
            res.push_back(get + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};