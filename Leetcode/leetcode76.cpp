// 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

// 示例：

// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"
// 说明：

// 如果 S 中不存这样的子串，则返回空字符串 ""。
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。

#include <string>
#include <vector>
#include <map>

using namespace std;

// 滑动窗口解决
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> dictT;   // 记录每个字母的数量
        for(int i = 0;i < t.length();i++) {
            if(dictT.count(t[i])) {
                dictT[t[i]]++;
            }
            else {
                dictT.insert(make_pair(t[i], 1)); // 初始化为1
            }
        }
        vector<int> f_index;    // s串中t中字符的出现位置
        for(int i = 0;i < s.length();i++) {
            if(dictT.count(s[i])) {
                f_index.push_back(i);
            }
        }
        map<char, int> window;  // 窗口的次数
        for(auto i = dictT.begin(); i != dictT.end();i++) {
            window.insert(make_pair(i->first, 0));
        }
        int r = 0, l = 0;
        int res[] = {-1, 0, 0};     // 长度 l r
        int curSize = 0;    // 已经匹配到的字符数量
        while (r < f_index.size()) {
            char c = s[f_index[r]];
            window[c]++;
            if(window[c] == dictT[c]) {
                curSize++;
            }
            // 如果已经找到所有的了 则开始缩小左边界
            while(l <= r && curSize == dictT.size()) {
                c = s[f_index[l]];
                int end = f_index[r];
                int start = f_index[l];
                if(res[0] == -1 || end-start+1 < res[0]) {  // 更新最小区间
                    res[0] = end - start + 1;
                    res[1] = start;
                    res[2] = end;
                }
                window[c]--;    //  向左移动
                if(window[c] < dictT[c]) {  // 如果有字符变少 则整体的字符数减少
                    curSize--;
                }
                l++;
            }
            r++;    // 从缩小后的最小区间开始向右拓展
        }
        return res[0] == -1 ? "" : s.substr(res[1], res[0]);
    }
};