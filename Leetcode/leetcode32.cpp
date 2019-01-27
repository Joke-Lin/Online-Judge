#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <memory.h>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> pairBracket;     // 使用栈存与当前右括号配对的左括号
        int maxPair[100000] = {};   // 以i结尾的最长有效括号对
        for(int i = 0;i < s.length();i++) {
            if(s[i] == '(') { // 左括号必为非法括号对
                pairBracket.push(i);
                maxPair[i] = 0;
            } else {
                if(pairBracket.empty()) {
                    maxPair[i] = 0;
                } else {
                    int pairIndex = pairBracket.top(); pairBracket.pop();
                    maxPair[i] = i - pairIndex + 1 + (pairIndex > 0 ? maxPair[pairIndex-1] : 0) ;
                    res = max(res,maxPair[i]);
                }
            }
        }
        return res;
    }
};